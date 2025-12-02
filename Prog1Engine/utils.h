#pragma once
#include "structs.h"
#include <vector>

namespace utils
{

	const float g_Pi{ 3.1415926535f };

#pragma region OpenGLDrawFunctionality
	void ClearBackground(float r, float g, float b);
	void ClearBackground();
	// Choose a floating point value for each color component between 0.0f and 1.0f. The a (alpha) is optional.
	// Usage: SetColor(1.0f, 0.0f, 0.0f); set the drawing color to red
	void SetColor(float r, float g, float b, float a = 1);
	// Pass a Color4f object to the function
	void SetColor(const Color4f& color);

	// Draws a line by connecting the two points specified by (x1,y1) and (x2,y2)
	void DrawLine(float x1, float y1, float x2, float y2, float lineWidth = 1.0f);
	// Draws a line by connecting the two points specified by p1 and p1
	void DrawLine(const Point2f& p1, const Point2f& p2, float lineWidth = 1.0f);

	void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float lineWidth = 1);
	void DrawTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3, float lineWidth = 1);
	void FillTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void FillTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3);
	void DrawRect(float left, float top, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Point2f& topLeft, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Rectf& rect, float lineWidth = 1.0f);
	void FillRect(float left, float top, float width, float height);
	void FillRect(const Point2f& topLeft, float width, float height);
	void FillRect(const Rectf& rect);

	void DrawEllipse(float centerX, float centerY, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Point2f& center, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Ellipsef& ellipse, float lineWidth = 1.0f);
	void FillEllipse(float centerX, float centerY, float radX, float radY);
	void FillEllipse(const Ellipsef& ellipse);
	void FillEllipse(const Point2f& center, float radX, float radY);

	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle);

	void DrawPolygon(const std::vector<Point2f>& vertices, bool closed = true, float lineWidth = 1.0f);
	void DrawPolygon(const Point2f* pVertices, size_t nrVertices, bool closed = true, float lineWidth = 1.0f);
	void FillPolygon(const std::vector<Point2f>& vertices);
	void FillPolygon(const Point2f* pVertices, size_t nrVertices);
#pragma endregion OpenGLDrawFunctionality

#pragma region TextureFunctionality

	struct Texture
	{
		GLuint id;
		float width;
		float height;
	};
	bool TextureFromFile(const std::string& path, Texture& texture);
	bool TextureFromString(const std::string& text, TTF_Font* pFont, const Color4f& textColor, Texture& texture);
	bool TextureFromString(const std::string& text, const std::string& fontPath, int ptSize, const Color4f& textColor, Texture& texture);
	void TextureFromSurface(const SDL_Surface* pSurface, Texture& textureData);
	void DrawTexture(const Texture& texture, const Point2f& dstTopLeft, float rotation = 0, const Rectf& srcRect = {});
	void DrawTexture(const Texture& texture, const Rectf& dstRect, float rotation = 0, const Rectf& srcRect = {});
	void DeleteTexture(Texture& texture);
#pragma endregion TextureFunctionality

#pragma region CollisionFunctionality
	float GetDistance(const float& x1, const float& y1, const float& x2, const float& y2);
	float GetDistance(const Point2f& p1, const Point2f& p2);

	bool IsPointInCircle(const float& centerX, const float& centerY, const float& radius, const float& pointX, const float& pointY);
	bool IsPointInCircle(const Point2f& centerPos, const float& radius, const Point2f& pointPos);
	bool IsPointInCircle(const Circlef& circle, const Point2f& pointPos);

	bool IsPointInRect(const float& left, const float& top, const float& width, const float& height, const float& pointX, const float& pointY);
	bool IsPointInRect(const Point2f& pos, const float& width, const float& height, const Point2f& pointPos);
	bool IsPointInRect(const Rectf& rect, const Point2f& pointPos);

	bool IsOverlapping(const float& centerX1, const float& centerY1, const float& radius1,
		const float& centerX2, const float& centerY2, const float& radius2);
	bool IsOverlapping(const Point2f& centerPos1, const float& radius1,
		const Point2f& centerPos2, const float& radius2);
	bool IsOverlapping(const Circlef& circle1, const Circlef& circle2);

	bool IsOverlapping(const float& left1, const float& top1, const float& width1, const float& height1,
		const float& left2, const float& top2, const float& width2, const float& height2);
	bool IsOverlapping(const Point2f& rectPos1, const float& width1, const float& height1,
		const Point2f& rectPos2, const float& width2, const float& height2);
	bool IsOverlapping(const Rectf& rect1, const Rectf& rect2);

	bool IsOverlapping(const Rectf& rect, const Circlef& circle);
	bool IsOverlapping(const float& radius, const float& circleX, const float& circleY, const float& RectX1, const float& RectY1,
		const float& RectX2, const float& RectY2);
#pragma endregion CollisionFunctionality

}