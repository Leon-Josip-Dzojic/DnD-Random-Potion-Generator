#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

/*
We create a vector for every property of the potion and load it with values.
For each potion a pseudo-random number, uniformally distributed number is generated
for every property. The number determines position in the property vector, that
we will take the property from. The end result being that a uniformally
distributed property is taken from the list of all properties.
End a uniformally random potion is created.

The numbers are psuedo-random but seeded with truly random numbers. Using the common
Mersenne Prime generator from the standard c++ library. See code lines: 101, 102.
*/
int main(int argc, char** argv)
{
    std::vector<std::string> title;
    std::vector<std::string> main_effect;
    std::vector<std::string> side_effect;
    std::vector<std::string> container;
    std::vector<std::string> label;
    std::vector<std::string> appearance;
    std::vector<std::string> appearance_2;
    std::vector<std::string> taste_and_smell;
    std::vector<std::string> texture;
    std::vector<std::string> potency;
    std::vector<std::string> quality;
    std::vector<std::string> duration;

    //We load the different values for the respective potion properties in the corresponding vector.
    std::ifstream d_title("titles.txt");//10 entries
    std::ifstream d_main_effect("main_effects.txt");//100 entries
    std::ifstream d_side_effect("side_effects.txt");//100 entries
    std::ifstream d_container("container.txt");//20 entries
    std::ifstream d_label("label.txt");//100 entries
    std::ifstream d_appearance("appearance.txt");//20 entries
    std::ifstream d_appearance_2("appearance_2.txt");//20 entries
    std::ifstream d_taste_and_smell("taste_and_smell.txt");//100 entries
    std::ifstream d_texture("textures.txt");//10 entries
    std::ifstream d_potency("potency.txt");//6 entries
    std::ifstream d_quality("quality.txt");//6 entries
    std::ifstream d_duration("duration.txt");//6 entries

    std::string line;
    std::string line_2;
    std::string line_3;
    std::string line_4;

    for(int i = 0; i < 6; i++)
    {
        getline(d_potency, line);
        potency.push_back(line);

        getline(d_quality, line_2);
        quality.push_back(line_2);

        getline(d_duration, line_3);
        duration.push_back(line_3);
    }

    for(int i = 0; i < 10; i++)
    {
        getline(d_title, line);
        title.push_back(line);

        getline(d_texture, line_2);
        texture.push_back(line_2);
    }

    for(int i = 0; i < 20; i++)
    {
        getline(d_container, line);
        container.push_back(line);

        getline(d_appearance, line_2);
        appearance.push_back(line_2);

        getline(d_appearance_2, line_3);
        appearance_2.push_back(line_3);
    }

    for(int i = 0; i < 100; i++)
    {
        getline(d_main_effect, line);
        main_effect.push_back(line);

        getline(d_side_effect, line_2);
        side_effect.push_back(line_2);

        getline(d_label, line_3);
        label.push_back(line_3);

        getline(d_taste_and_smell, line_4);
        taste_and_smell.push_back(line_4);
    }

    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> six_dis(0,5);
    std::uniform_int_distribution<int> ten_dis(0,9);
    std::uniform_int_distribution<int> twenty_dis(0,19);
    std::uniform_int_distribution<int> hundred_dis(0,99);

    for(int i = 0; i < 5000; i++)
    {
        std::string p_title = title[ten_dis(generator)];
        std::string p_main_effect = main_effect[hundred_dis(generator)];
        std::string p_side_effect = side_effect[hundred_dis(generator)];
        std::string p_container = container[twenty_dis(generator)];
        std::string p_label = label[hundred_dis(generator)];
        std::string p_appearance = appearance[twenty_dis(generator)];
        std::string p_appearance_2 = appearance_2[twenty_dis(generator)];
        std::string p_taste = taste_and_smell[hundred_dis(generator)];
        std::string p_smell = taste_and_smell[hundred_dis(generator)];
        std::string p_texture = texture[ten_dis(generator)];
        std::string p_potency = potency[six_dis(generator)];
        std::string p_quality = quality[six_dis(generator)];
        std::string p_duration = duration[six_dis(generator)];

        std::cout << "Title: " << p_title << std::endl;
        std::cout << "Main effect: " << p_main_effect << std::endl;

        if(p_quality != "Perfect.")
        {
            std::cout << "Side effect: " << p_side_effect << std::endl;
        }
        else
        {
            std::cout << "Perfect potions do not have side effects!" << std::endl;
        }

        std::cout << "Container: " << p_container << std::endl;
        std::cout << "The label is: " << p_label << std::endl;

        //std::cout << "The liquid is: " << p_appearance << std::endl;
        //std::cout << "The liquid has: " << p_appearance_2 << std::endl;
        std::cout << "The liquid is: " << p_appearance << " with " << p_appearance_2 << std::endl;
        std::cout << "Taste: " << p_taste << std::endl;
        std::cout << "Smell: " << p_smell << std::endl;
        std::cout << "Texture: " << p_texture << std::endl;
        std::cout << "Potency: " << p_potency << std::endl;
        std::cout << "Quality: " << p_quality << std::endl;
        std::cout << "Duration: " << p_duration << std::endl;
        std::cout << std::endl;
    }
    return 0;
}

/*
Take care about the line ending sequences of your files. It is best to create the text
files on the system the code is going to be runnning on. Creating on Windows and then
moving to Linux can cause hard to find issues.
*/