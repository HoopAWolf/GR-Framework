#include "RenderHelper.h"
#include "Mesh.h"
#include "GraphicsManager.h"
#include "ShaderProgram.h"
#include "MatrixStack.h"

void RenderHelper::RenderMesh(Mesh* _mesh)
{
	// Get all our transform matrices & update shader
	Mtx44 MVP;
	GraphicsManager* g = GraphicsManager::GetInstance();
	if (g->m_renderPass == g->RENDER_PASS_PRE)
	{
		Mtx44 lightDepthMVP = g->m_lightDepthProj *
			g->m_lightDepthView * g->GetModelStack().Top();
		glUniformMatrix4fv(g->gPass_params[g->U_LIGHT_DEPTH_MVP_GPASS], 1,
			GL_FALSE, &lightDepthMVP.a[0]);
		//mesh->Render();

		for (int i = 0; i < MAX_TEXTURES; ++i)
		{
			if (_mesh->textureID[i] > 0)
			{
				glUniform1i(g->gPass_params[g->U_SHADOW_COLOR_TEXTURE_ENABLED + i], 1);
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, _mesh->textureID[i]);
				glUniform1i(g->gPass_params[g->U_SHADOW_COLOR_TEXTURE + i], i);
			}
			else
				glUniform1i(g->gPass_params[g->U_SHADOW_COLOR_TEXTURE_ENABLED + i], 0);
		}
		_mesh->Render();
		return;
	}

	MVP = GraphicsManager::GetInstance()->GetProjectionMatrix() * GraphicsManager::GetInstance()->GetViewMatrix() * GraphicsManager::GetInstance()->GetModelStack().Top();
	ShaderProgram* currProg = GraphicsManager::GetInstance()->GetActiveShader();
	currProg->UpdateMatrix44("MVP", &MVP.a[0]);

	// Disable lighting stuff
	currProg->UpdateInt("lightEnabled", 0);

	//update texture
	for (int i = 0; i < MAX_TEXTURES; ++i)
	{
		if (_mesh->textureID[i] > 0)
		{
			currProg->UpdateInt("colorTextureEnabled[" + std::to_string(i) + "]", 1);
			GraphicsManager::GetInstance()->UpdateTexture(i, _mesh->textureID[i]);
			currProg->UpdateInt("colorTexture[" + std::to_string(i) + "]", 0);

		}
		else//no texture
		{
			currProg->UpdateInt("colorTextureEnabled[" + std::to_string(i) + "]", 0);
		}
	}

	// Do actual rendering
	_mesh->Render();

	// Unbind texture for safety (in case next render call uses it by accident)
	if (_mesh->textureID > 0)
	{
		GraphicsManager::GetInstance()->UnbindTexture(0);
	}
}

void RenderHelper::RenderMeshWithLight(Mesh* _mesh)
{
	// Get all our transform matrices & update shader
	Mtx44 MVP, modelView, modelView_inverse_transpose;
	GraphicsManager* g = GraphicsManager::GetInstance();
	if (g->m_renderPass == g->RENDER_PASS_PRE)
	{
		Mtx44 lightDepthMVP = g->m_lightDepthProj * g->m_lightDepthView * g->GetModelStack().Top();
		glUniformMatrix4fv(g->gPass_params[g->U_LIGHT_DEPTH_MVP_GPASS], 1, GL_FALSE, &lightDepthMVP.a[0]);
		//mesh->Render();

		for (int i = 0; i < MAX_TEXTURES; ++i)
		{
			if (_mesh->textureID[i] > 0)
			{
				glUniform1i(g->gPass_params[g->U_SHADOW_COLOR_TEXTURE_ENABLED + i], 1);
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, _mesh->textureID[i]);
				glUniform1i(g->gPass_params[g->U_SHADOW_COLOR_TEXTURE + i], i);
			}
			else
				glUniform1i(g->gPass_params[g->U_SHADOW_COLOR_TEXTURE_ENABLED + i], 0);
		}
		_mesh->Render();

		return;
	}

	MVP = GraphicsManager::GetInstance()->GetProjectionMatrix() * GraphicsManager::GetInstance()->GetViewMatrix() * GraphicsManager::GetInstance()->GetModelStack().Top();
	ShaderProgram* currProg = GraphicsManager::GetInstance()->GetActiveShader();
	currProg->UpdateMatrix44("MVP", &MVP.a[0]);

	// Update light stuff
	currProg->UpdateInt("lightEnabled", 1);
	modelView = GraphicsManager::GetInstance()->GetViewMatrix() * GraphicsManager::GetInstance()->GetModelStack().Top();
	currProg->UpdateMatrix44("MV", &modelView.a[0]);
	modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
	currProg->UpdateMatrix44("MV_inverse_transpose", &modelView.a[0]);

	Mtx44 lightDepthMVP = g->m_lightDepthProj *
		g->m_lightDepthView * g->GetModelStack().Top();

	glUniformMatrix4fv(g->GetActiveShader()->GetUniform("lightDepthMVP"), 1,
		GL_FALSE, &lightDepthMVP.a[0]);

	//load material
	currProg->UpdateVector3("material.kAmbient", &_mesh->material.kAmbient.r);
	currProg->UpdateVector3("material.kDiffuse", &_mesh->material.kDiffuse.r);
	currProg->UpdateVector3("material.kSpecular", &_mesh->material.kSpecular.r);
	currProg->UpdateFloat("material.kShininess", _mesh->material.kShininess);
	
	// Update textures first if available
	//if (_mesh->textureID > 0)
	//{
	//	currProg->UpdateInt("colorTextureEnabled", 1);
	//	GraphicsManager::GetInstance()->UpdateTexture(0, _mesh->textureID);
	//	currProg->UpdateInt("colorTexture", 0);
	//}
	//else
	//{
	//	currProg->UpdateInt("colorTextureEnabled", 0);
	//}
	//update texture
	for (int i = 0; i < MAX_TEXTURES; ++i)
	{
		if (_mesh->textureID[i] > 0)
		{
			currProg->UpdateInt("colorTextureEnabled[" + std::to_string(i) + "]", 1);
			GraphicsManager::GetInstance()->UpdateTexture(i, _mesh->textureID[i]);
			currProg->UpdateInt("colorTexture[" + std::to_string(i) + "]", 0);

		}
		else//no texture
		{
			currProg->UpdateInt("colorTextureEnabled[" + std::to_string(i) + "]", 0);
		}
	}

	// Do actual rendering
	_mesh->Render();

	// Unbind texture for safety (in case next render call uses it by accident)
	if (_mesh->textureID > 0)
	{
		GraphicsManager::GetInstance()->UnbindTexture(0);
	}
}

void RenderHelper::RenderText(Mesh* _mesh, const std::string& _text, Color _color)
{
	// Trivial Rejection : Unable to render without mesh or texture
	if (!_mesh || _mesh->textureID <= 0)
		return;

	ShaderProgram* currProg = GraphicsManager::GetInstance()->GetActiveShader();

	currProg->UpdateInt("textEnabled", 1);
	currProg->UpdateVector3("textColor", &_color.r);
	currProg->UpdateInt("lightEnabled", 0);
	currProg->UpdateInt("colorTextureEnabled", 1);
	
	currProg->UpdateInt("colorTextureEnabled", 1);
	GraphicsManager::GetInstance()->UpdateTexture(0, _mesh->textureID[0]);
	currProg->UpdateInt("colorTexture", 0);

	for (unsigned i = 0; i < _text.length(); ++i)
	{
		Mtx44 characterSpacing, MVP;
		//characterSpacing.SetToTranslation((i+0.5f) * 1.0f, 0, 0); // 1.0f is the spacing of each character, you may change this value
		characterSpacing.SetToTranslation((float)(1 + (int)i), 0.0f, 0.0f); // 1.0f is the spacing of each character, you may change this value
		MVP = GraphicsManager::GetInstance()->GetProjectionMatrix() * GraphicsManager::GetInstance()->GetViewMatrix() * GraphicsManager::GetInstance()->GetModelStack().Top() * characterSpacing;
		currProg->UpdateMatrix44("MVP", &MVP.a[0]);

		_mesh->Render((unsigned)_text[i] * 6, 6);
	}

	GraphicsManager::GetInstance()->UnbindTexture(0);
	currProg->UpdateInt("textEnabled", 0);
}