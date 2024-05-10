// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
 
char* formatText(char* text) 
{
    char* refText = NULL;
    // write your logic here
    return text;
}
 
    
int findLettersCount(char* text)
{
    return 0;
}
 
int findWordCount(char* text)
{
    return 0;
}
int main() {
    char largeText[] = 
    "According to the TIOBE  Index, C++ consistently ranks among the top programming languages, maintaining its relevance  and popularity over the years. The Global  Programming Language Ranking by RedMonk places C++ in the top tier, emphasizing its  importance in both enterprise and open-source development. Employment Landscape: Job portals report a robust demand for  C++ developers, with an average of 50,000+ open positions worldwide at any given time. In the United States alone, the Bureau of Labor Statistics projects a 15% growth in software  developer jobs by 2029, significantly outpacing the average for all occupations.Salary Trends: C++ developers command competitive salaries, with average annual earnings ranging from $70,000 to $120,000, depending on factors  such as experience, location, and industry. Tech hubs like Silicon Valley, Seattle, and New  York offer premium compensation packages for C++ professionals, often exceeding national  averages by 20% or more.";
 
    cout<<"Large Text:"<<endl;
    cout << largeText<<endl;
 
    int letCount = findLettersCount(largeText);
    int wordCount = findWordCount(largeText);
    cout<<"Letters count in largeText : "<<letCount<<endl;
    cout<<"Word count in largeText : "<<wordCount<<endl;
    char* refinedText = formatText(largeText);
    letCount = findLettersCount(refinedText);
    wordCount = findWordCount(refinedText);
    cout<<endl<<"Refined Text:"<<endl;
    cout<<refinedText<<endl;
    cout<<"Letters count in refinedText : "<<letCount<<endl;
    cout<<"Word count in refinedText : "<<wordCount<<endl;
 
    return 0;
}