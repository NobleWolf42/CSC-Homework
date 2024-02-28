/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef MILEAGETRACKERNODEH
#define MILEAGETRACKERNODEH
#include <string>

using std::string;

class MileageTrackerNode {
   public:
      // Constructor
      MileageTrackerNode();

      // Destructor
      ~MileageTrackerNode();

      // Constructor
      MileageTrackerNode(double milesInit, string dateInit);

      /* Insert node after this node.
      Before: this -- next
      After:  this -- node -- next
      */

      double GetMiles();

      string GetDate();

      void InsertAfter(MileageTrackerNode* nodeLoc);

      // Get location pointed by nextNodeRef
      MileageTrackerNode* GetNext();

      void PrintNodeData();

   private:
      double miles;         // Node data
      string date;          // Node data
      MileageTrackerNode* nextNodeRef; // Reference to the next node
};



#endif
