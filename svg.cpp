#include"svg.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}
void svg_text(double left,double baseline, string text)
{
    cout<< "<text x='" << left << "' y='"<<baseline<<"'>'"<<text<<"'</text>";
}
void svg_rect(double x, double y, double width, double height,string stroke = "black",string fill = "black")
{
    cout<<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"'/>";
}

string
make_info_text(double top) {
    stringstream buffer;
    // TODO: получить версию системы, записать в буфер.
    // TODO: получить имя компьютера, записать в буфер.
    DWORD dwVersion =0;
    dwVersion =GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = dwVersion & mask;
    DWORD platform = dwVersion >>16;
    DWORD build = platform;

    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD mask_major = 0b00000000'00000000'00000000'11111111;
    dwMajorVersion = version & mask_major;
    dwMinorVersion = version >> 8;
    char buffer2[MAX_COMPUTERNAME_LENGTH+1];
    DWORD size;
	size=sizeof(buffer2);
    GetComputerName(buffer2,&size);
    int q= top+50;
    int x=20;
    string str="Computer name:";
    buffer<<"Windows v "<<dwMajorVersion<<"."<<dwMinorVersion<<" build("<<build<<")"<<"</text>"<< "<text x='" << x << "' y='"<<q<<"'>"<<str<<buffer2<<"</text>";
    return buffer.str();
}
void svg_text2(string buffer,double top,double left)
{

 cout<< "<text x='" << left << "' y='"<<top+30<<"'>"<<buffer;
}
void show_histogram_svg(const vector<size_t>& bins)
{
    string stroke;
    string fill;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 700;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BLOCK_WIDTH = 10;
    const auto BIN_HEIGHT =30;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top=0;
    for(size_t bin:bins)
    {
        const double bin_width =BLOCK_WIDTH*bin;
        svg_text(TEXT_LEFT,top+TEXT_BASELINE,to_string(bin));
        svg_rect(TEXT_WIDTH,top,bin_width,BIN_HEIGHT,stroke="black",fill="black");
        top+=BIN_HEIGHT;
    }
    string buffer;
    buffer=make_info_text(top);
    cout <<endl;
    svg_text2(buffer,top,TEXT_LEFT);
    svg_end();
}
void show_histogram_text(const vector<size_t>& bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}
