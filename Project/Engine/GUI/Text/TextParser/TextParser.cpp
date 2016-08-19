#include "TextParser.hpp"
#include "../../../../Vector.h"
#include "Comparer\CompareArgument.hpp"
#include "Comparer\CompareResultTypes.hpp"

#define LIST_DOT 0x25CF

namespace GUI
{
	namespace Parser
	{
		void TextParser::calculateTextureSize(sf::String& m_text, std::vector<Parser::ParseArgument::BaseParseArgument*>& args)
		{
			size_t i = 0;
			size_t size = m_text.getSize();
			sf::String argPos;
			size_t currentArgument = 0;
			for (i = 0; i < size; i++)
			{
				glyph = settings.font.getGlyph(m_text[i], settings.charSize, false);
				if (i < size - 1)
					kerning = settings.font.getKerning(m_text[i], m_text[i + 1], settings.charSize);

				if (m_text[i] == '\n')
					NewLine();
				else if (m_text[i] == '{')
				{
					parseArgument = true;
					argPos.clear();
				}
				else if (m_text[i] == '}')
				{
					if (parseArgument)
					{
						parseArgument = false;
						size_t pos;
						if (argPos.isEmpty())
						{
							pos = currentArgument;
							currentArgument++;
						}
						else
							pos = std::stoi(argPos.operator std::wstring());
						if (pos < args.size())
						{
							Parser::ParseArgument::BaseParseArgument* bpa = args[pos];
							switch (bpa->type)
							{
							case Parser::ParseArgument::BaseParseArgument::Compare:
							{
								for each (char ch in doCompareArgument(bpa))
								{
									glyph = settings.font.getGlyph(ch, settings.charSize, false);
									advance += (glyph.advance + settings.characterSpacing);
									if (texSize.x <= advance)
										texSize.x = advance;
								}
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::Reference:
							{
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::BeginList:
							{
				
								listIndex++;
								if (advance > 0)
									NewLine();
								else
									advance += listIndex * 4;
								glyph = settings.font.getGlyph(LIST_DOT, settings.charSize, false);
								advance += (glyph.advance + settings.characterSpacing + kerning);
								if (texSize.x <= advance)
									texSize.x = advance;
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::NewListLine:
							{
								NewLine();
								newLine += 5;
				
								glyph = settings.font.getGlyph(LIST_DOT, settings.charSize, false);
				
								advance += (glyph.advance + settings.characterSpacing + kerning);
								if (texSize.x <= advance)
									texSize.x = advance;
				
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::EndList:
							{
								listIndex--;
								NewLine();
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::Icon:
								break;
							case Parser::ParseArgument::BaseParseArgument::None:
								break;
							}
						}
					}
				}
				else if (parseArgument)
				{
					if (isdigit(m_text[i]))
						argPos += (m_text[i]);
				}
				else
				{
					advance += (glyph.advance + settings.characterSpacing + kerning);
					if (texSize.x <= advance)
						texSize.x = advance;
				}
			}
			texSize.y = newLine + lineSpacing+2;
			newLine = 0;
			advance = 0;
			m_parsedTextTexture.create(texSize.x, texSize.y);
		}
		void TextParser::createTexture(sf::String& m_text, std::vector<Parser::ParseArgument::BaseParseArgument*>& args)
		{
			size_t i = 0;
			size_t size = m_text.getSize();
			sf::String argPos;
			size_t currentArgument = 0;
			for (i = 0; i < size; i++)
			{
				glyph = settings.font.getGlyph(m_text[i], settings.charSize, false);
				if (i < size - 1)
					kerning = settings.font.getKerning(m_text[i], m_text[i + 1], settings.charSize);
				sprite.setTextureRect(glyph.textureRect);
				if (m_text[i] == '\n')
					NewLine();
				else if (m_text[i] == '{')
				{
					parseArgument = true;
					argPos.clear();
				}
				else if (m_text[i] == '}')
				{
					if (parseArgument)
					{
						parseArgument = false;
						size_t pos;
						if (argPos.isEmpty())
						{
							pos = currentArgument;
							currentArgument++;
						}
						else
							pos = std::stoi(argPos.operator std::wstring());
						if (pos < args.size())
						{
							Parser::ParseArgument::BaseParseArgument* bpa = args[pos];
							switch (bpa->type)
							{
							case Parser::ParseArgument::BaseParseArgument::Compare:
							{
								for each (char ch in doCompareArgument(bpa))
								{
									if (ch == '-')
										sprite.setColor(sf::Color::Red);
									else if (ch == '+')
										sprite.setColor(sf::Color::Green);
									glyph = settings.font.getGlyph(ch, settings.charSize, false);
									sprite.setTextureRect(glyph.textureRect);
									sprite.setPosition(advance + glyph.bounds.left, newLine + glyph.bounds.top + settings.font.getLineSpacing(settings.charSize));
									advance += (glyph.advance + settings.characterSpacing + kerning);
									m_parsedTextTexture.draw(sprite);
								}
								sprite.setColor(settings.color);
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::Reference:
							{
								doReferenceArgument(bpa);
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::BeginList:
							{
								listIndex++;
								if (advance > 0)
									NewLine();
								else
									advance += listIndex * 4;
				
								glyph = settings.font.getGlyph(LIST_DOT, settings.charSize, false);
								sprite.setTextureRect(glyph.textureRect);
								sprite.setPosition(advance + glyph.bounds.left, newLine + glyph.bounds.top + settings.font.getLineSpacing(settings.charSize));
								advance += (glyph.advance + settings.characterSpacing + kerning);
								m_parsedTextTexture.draw(sprite);
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::NewListLine:
							{
								NewLine();
								newLine += 5;
				
								glyph = settings.font.getGlyph(LIST_DOT, settings.charSize, false);
								sprite.setTextureRect(glyph.textureRect);
				
								sprite.setPosition(advance + glyph.bounds.left, newLine + glyph.bounds.top + settings.font.getLineSpacing(settings.charSize));
								advance += (glyph.advance + settings.characterSpacing + kerning);
				
								m_parsedTextTexture.draw(sprite);
				
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::EndList:
							{
								listIndex--;
								NewLine();
								break;
							}
							case Parser::ParseArgument::BaseParseArgument::Icon:
								break;
							case Parser::ParseArgument::BaseParseArgument::None:
								break;
							}
						}
					}
				}
				else if (parseArgument)
				{
					if (isdigit(m_text[i]))
						argPos += (m_text[i]);
				}
				else
				{
					sprite.setPosition(advance + glyph.bounds.left , newLine + glyph.bounds.top + settings.font.getLineSpacing(settings.charSize));
					advance += (glyph.advance + settings.characterSpacing + kerning);
					m_parsedTextTexture.draw(sprite);
				}
			}
		}
		void TextParser::NewLine()
		{
			advance = 0;
			newLine += (settings.font.getLineSpacing(settings.charSize));
			if (listIndex > -1)
			{
				advance += listIndex * 4;
				glyph = settings.font.getGlyph(LIST_DOT, settings.charSize, false);
				advance += (glyph.advance + settings.characterSpacing + kerning);
			}
		}
		std::string TextParser::doCompareArgument(Parser::ParseArgument::BaseParseArgument * argument)
		{
			Parser::ParseArgument::BaseCompareArgument* bca = ((Parser::ParseArgument::BaseCompareArgument*)argument);
			switch (bca->comparingType)
			{
			case Parser::ParseArgument::BaseCompareArgument::CompareType::Int:
			{
				return doCompareResult<Parser::ParseArgument::IntCompareResult,int>(argument);
			}
			case Parser::ParseArgument::BaseCompareArgument::CompareType::Double:
				return doCompareResult<Parser::ParseArgument::DoubleCompareResult, double>(argument);
			};
			return "<CompareTypeInvalid>";
		}
		void TextParser::doReferenceArgument(Parser::ParseArgument::BaseParseArgument * argument)
		{
		}
		TextParser::TextParser(ParserSettings _settings) : settings(_settings)
		{
		}
		void TextParser::setParserSettings(ParserSettings _settings)
		{
			settings = _settings;
		}

		const sf::Texture& TextParser::parse(sf::String& m_text, std::vector<Parser::ParseArgument::BaseParseArgument*>& args)
		{
			const sf::Texture& tex = settings.font.getTexture(settings.charSize);
			sprite.setTexture(tex, true);
			sprite.setColor(settings.color);
			
			texSize.x = texSize.y = 0;
			advance = 0;
			kerning = 0;
			newLine = 0;
			lineSpacing = settings.font.getLineSpacing(settings.charSize);

			calculateTextureSize(m_text,args);
			createTexture(m_text,args);

			m_parsedTextTexture.display();
			return m_parsedTextTexture.getTexture();
		}
	}
}