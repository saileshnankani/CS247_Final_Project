#ifndef INTERVIEWER_H_
#define INTERVIEWER_H_

#include "character.h"
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>

// Separate from the NPC class because conversations are a tree,
// Interviews are a linear set of questions
// Interviews also should not be taken again.
class Interviewer : public Character
{
public:
    // Interviews are just a sequence of questions, to which the answers
    // are given a certain score. If the total score passes a threshold
    // by the end of the interview, the interview is passed.
    class Interview
    {
    public:
        enum InterviewState
        {
            UNATTEMPTED,
            PASSED,
            FAILED
        };

        Interview(std::ifstream &interviewerFile);

        void begin();

        bool wasPassed();

        static int getNumberOfInterviewsFailed();

    private:
        static int numberOfInterviewsFailed;
        class InterviewNode
        {
            std::string question;
            // A vector that maps an answer number (the index of the vector)
            // to a pair of:
            //  - the sentence associated with the answer
            //  - the score associated with the answer
            std::vector<std::pair<std::string, int>> answers;

        public:
            InterviewNode(std::string question, std::vector<std::pair<std::string, int>> &&answers);
            void print() const;
            int scoreForAnswer(int answerNumber) const;
        };

        InterviewState state;
        int totalScore;

        // A chain of questions and their potential answers
        std::vector<InterviewNode> interviewNodes;
    };
private:
    Interview interview;

public:
    Interviewer(int x, int y, std::ifstream &interviewerFile, char displayLetter);
    bool interviewWasPassed();
    void notify(Player &source);
    void notify(Enemy &source);
    void interactFromTileToTile(Tile &from, Tile &to, std::pair<int, int> targetCoords) override;
};

#endif