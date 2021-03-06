/*
The MIT License (MIT)

Copyright (c) 2015 Cameron Buschardt

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <vector>
#include <memory>
#include <stdint.h>
#include <string>

class psd {
public:
    typedef uint32_t pixel;     // GL_RGBA

    struct layer {
        std::vector<std::string> name;     // PSD Folder path
        std::vector<pixel> pixels;
        uint32_t width, height; // Same as parent

		uint32_t right, bottom; // wtkurooka add
		uint32_t left, top; // wtkurooka add
		bool	hide;
		int		opacity;
	
		layer& operator =(layer& t)
		{
			name = t.name;
			pixels = t.pixels;
			width = t.width;
			height = t.height;
			right = t.right;
			bottom = t.bottom;
			left = t.left;
			top = t.top;
			hide = t.hide;
			opacity = t.opacity;

			return *this;
		}
	};

    uint32_t width, height;
    std::vector<std::shared_ptr<layer> > layers;

    bool load(const std::string & filename);


};
