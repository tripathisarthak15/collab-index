// Include header file
#include <iostream>
#include <string>
#include <vector>
/* This class are provide by kalkicode.com (java to c++) */

class Settlement {
	public:
	// returns a value of standard input in c++
	template < typename T > static T input() {
		T value;
		std::cin >> value;
		return value;
	}
// convert string to vector character
static std::vector < char > string_to_char_vector(std::string text) {
	std::vector < char > record;
	// Get string character into vector
	for (int i = 0; i < text.size(); i++) {
		record.push_back(text[i]);
	}
	// Return result
	return record;
}
};
class Result
{
    //     * Complete the 'findSubstring' function below.
    //     *
    //     * The function is expected to return a STRING.
    //     * The function accepts following parameters:
    //     *  1. STRING s
    //     *  2. INTEGER k
    public:
    static std::vector<std::string> findSubstring(std::string s, int k)
    {
        // Write your code here
        std::vector<char> array = Settlement::string_to_char_vector(s);
        int a = 0;
        int b = k;
        int previous_C = 0;
        std::string previous_W = "";
        std::vector<std::string> array2(2);
        int c = 0;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u')
            {
                c++;
                break;
            }
            else 
            {
                if (c != 0)
                {
                    array2[0] = "Not found!";
                }
            }
        }
        if (c != 0)
        {
            while (a != (array.size() - k + 1))
            {
                int count = 0;
                std::string word = "";
                for (int i = a; i < b; i++)
                {
                    if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u')
                    {
                        count++;
                    }
                    while (i == 0)
                    {
                        previous_C = count;
                        break;
                    }
                    word += "" + std::to_string(array[i]);
                }
                while (a == 0)
                {
                    previous_W = word.toString();
                    break;
                }
                a++;
                b++;
                if (count > previous_C && previous_C != 0)
                {
                    previous_C = count;
                    previous_W = word.toString();
                }
            }
        }
        if (c != 0)
        {
            array2[0] = previous_W;
        }
        array2[1] = (to_string(previous_C));
        return array2;
    }
};
class Solution
{
    public:
    static void main(std::vector<std::string> &args) throws IOException
    {
        System.gc();
        Scanner sc =  java.util.Scanner(java.io.BufferedInputStream@77afea7d);
        std::string s = Settlement::input<std::string>();
        int k = Settlement::input<int>();
        std::vector<std::string> result = Result::findSubstring(s, k);
        if (result[0] == nullptr)
        {
            std::cout << "Not found!" << std::endl;
        }
        else 
        {
            std::cout << result[0] << std::endl;
        }
        // System.out.println(result[1]);
        System.gc();
    }
};
int main(int argc, char **argv){
	std::vector<std::string> parameter(argv + 1, argv + argc);
	Solution::main(parameter); 
	return 0;
};