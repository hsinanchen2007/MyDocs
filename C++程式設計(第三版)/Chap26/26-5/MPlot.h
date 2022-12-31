// MPlot.cpp
// --------------------------------------
using namespace ODEParameters;
void XYPlot(Matrix& X)
{
   int i;
   fstream OutFile(FileName1, ios::out);
   if (!OutFile) {cout<< "File: " << FileName1
      << "存檔失敗!" << endl; exit(1);}
   OutFile << "clear all" << endl;
   OutFile << "x = [" << endl;
   for (i = 1; i<= NoPoint; i++)
       OutFile << setw(8)
               << setiosflags(ios::fixed)
               << setiosflags(ios::right)
               << setiosflags(ios::showpoint)
               << setprecision(5)
               << X[1][i] << endl;
   OutFile << "];" << endl;
   OutFile << "y = [" << endl;
   for (i = 1; i<= NoPoint; i++)
       OutFile << setw(8)
               << setiosflags(ios::fixed)
               << setiosflags(ios::right)
               << setiosflags(ios::showpoint)
               << setprecision(5)
               << X[2][i] << endl;
   OutFile << "];" << endl;
   OutFile << "plot(x,y)" << endl;
   OutFile << "title ('"  << TitleA    << "')" << endl;
   OutFile << "xlabel('"  << XLabelA   << "')" << endl;
   OutFile << "ylabel('"  << YLabelA   << "')" << endl;
   OutFile << "grid on"   << endl;
   OutFile.close();
   cout    << "已經存於 " << FileName1 << endl;
   return;
}

void TXPlot(Matrix& X)
{
   fstream OutFile(FileName2, ios::out);
   if (!OutFile) {cout<< "File: " << FileName2
      << "存檔失敗!" << endl; exit(1);}
   OutFile << "clear all" << endl;
   OutFile << "X = [" << endl;
   for (int i = 1; i<= NoPoint; i++)
       OutFile << setiosflags(ios::fixed)
               << setiosflags(ios::right)
               << setiosflags(ios::showpoint)
               << setprecision(5)
               << setw(8)
               << X[1][i]  << "  "
               << X[2][i]  << ';'  << endl;
   OutFile << "];"    << endl;
   OutFile << "h = "  << h << ";"  << endl;
   OutFile << "t=[0:" << NoPoint-1 << "]*h;" << endl;
   OutFile << "set(0, 'defaultaxeslinestyleorder','-|-.');"
           << endl;
   OutFile << "set(0, 'defaultaxescolororder', [0 0 0]);"
           << endl;
   OutFile << "plot(t,X), legend('"    << X1Name
           << "', '"      << X2Name    << "')" << endl;
   OutFile << "title ('"  << TitleB    << "')" << endl;
   OutFile << "xlabel('"  << XLabelB   << "')" << endl;
   OutFile << "ylabel('"  << YLabelB   << "')" << endl;
   OutFile << "grid on"   << endl;
   OutFile.close();
   cout    << "已經存於 " << FileName2 << endl;
   return;
}

