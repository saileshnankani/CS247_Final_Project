#include "interviewer.h"

Interviewer::Interview::InterviewNode::InterviewNode(std::string question, std::vector<std::pair<std::string, int>> &&answers) : question{question}, answers{std::move(answers)} {}

void Interviewer::Interview::InterviewNode::print() const
{
    // TODO: replace this with actual output
    std::cout << question << std::endl;
    for (int i = 0; i < answers.size(); ++i)
    {
        // TODO: replace this with actual output
        // answer.first is the string representing the potential answer
        std::cout << i << ". " << answers.at(i).first << std::endl;
    }
}

int Interviewer::Interview::InterviewNode::scoreForAnswer(int answerNumber) const
{
    return answers.at(answerNumber).second;
}

Interviewer::Interview::Interview(std::ifstream &interviewerFile) : state{Interview::UNATTEMPTED}, totalScore{0}
{
    int numberOfQuestions;
    interviewerFile >> numberOfQuestions;

    // Eat the newline character
    std::string newline;
    std::getline(interviewerFile, newline);
    for (int i = 0; i < numberOfQuestions; ++i)
    {
        std::string question;
        std::string numberOfAnswers;
        std::getline(interviewerFile, question);
        std::getline(interviewerFile, numberOfAnswers);
        std::vector<std::pair<std::string, int>> answers;

        for (int j = 0; j < std::stoi(numberOfAnswers); ++j)
        {
            std::string answer;
            std::string score;
            std::getline(interviewerFile, answer);
            std::getline(interviewerFile, score);
            answers.emplace_back(answer, std::stoi(score));
        }
        interviewNodes.emplace_back(question, std::move(answers));
    }
}

int Interviewer::Interview::numberOfInterviewsFailed = 0;

bool Interviewer::Interview::wasPassed(){
    return state == PASSED;
}

void Interviewer::Interview::begin()
{
    if (state == UNATTEMPTED)
    {

        for (const auto &interviewNode : interviewNodes)
        {
            interviewNode.print();
            int answerNumber;
            // TODO: replace this with actual input
            std::cin >> answerNumber;
            totalScore += interviewNode.scoreForAnswer(answerNumber);
        }
        // At the end, we see if the interview was passed or not (we assume you need to have a total score of at least floor(# of interviewNodes / 2))
        if (totalScore >= interviewNodes.size() / 2)
        {
            state = PASSED;
            std::cout << "You passed that interview!" << std::endl;
        }
        else
        {
            state = FAILED;
            std::cout << "You didn't pass that interview... Game Over!" << std::endl;
            ++numberOfInterviewsFailed;
        }
    }
    else
    {
        std::cout << "You have already attended this interview" << std::endl;
    }
}

int Interviewer::Interview::getNumberOfInterviewsFailed(){
    return numberOfInterviewsFailed;
}

Interviewer::Interviewer(int x, int y, std::ifstream &interviewerFile, char displayLetter) : Character{x, y, displayLetter}, interview{interviewerFile} {}

bool Interviewer::interviewWasPassed(){
    return interview.wasPassed();
}

void Interviewer::notify(Player &source)
{
    interview.begin();
}

void Interviewer::notify(Enemy &source)
{
    // Do nothing; Enemies should not do anything when targeting an NPC.
}

void Interviewer::interactFromTileToTile(Tile &from, Tile &to, std::pair<int, int> targetCoords)
{
    // Interviewers don't interact.
}
