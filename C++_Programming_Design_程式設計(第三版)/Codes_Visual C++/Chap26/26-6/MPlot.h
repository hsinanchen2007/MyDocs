// MPlot.cpp
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// ���{�����v�ݩ� �iģ��
// �ϥήɥ����n��.
// --------------------------------------
using namespace ODEParameters;
void XYPlot(Matrix& X)
{
   int i;
   fstream OutFile(FileName1, ios::out);
   if (!OutFile) {cout<< "File: " << FileName1
      << "�s�ɥ���!" << endl; exit(1);}
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
               << X[3][i] << endl;
   OutFile << "];" << endl;
   OutFile << "plot(x,y)" << endl;
   OutFile << "title ('"  << TitleA    << "')" << endl;
   OutFile << "xlabel('"  << XLabelA   << "')" << endl;
   OutFile << "ylabel('"  << YLabelA   << "')" << endl;
   OutFile << "grid on"   << endl;
   OutFile.close();
   cout    << "�w�g�s�� " << FileName1 << endl;
   return;
}
// �w�q��� XYZPlot() �H�۰ʲ��� MATLAB �� 3D ø�ϫ��Ovoid XYZPlot(Matrix& X)
void XYZPlot(Matrix& X)
{
   int i;
   fstream OutFile(FileName2, ios::out);
   if (!OutFile) {cout<< "File: " << FileName2
      << "�s�ɥ���!" << endl; exit(1);}
   OutFile << "clear all" << endl;
   OutFile << "x1 = [" << endl;
   for (i = 1; i<= NoPoint; i++)
       OutFile << setw(8)
               << setiosflags(ios::fixed)
               << setiosflags(ios::right)
               << setiosflags(ios::showpoint)
               << setprecision(5)
               << X[1][i] << endl;
   OutFile << "];" << endl;
   OutFile << "x2 = [" << endl;
   for (i = 1; i<= NoPoint; i++)
       OutFile << setw(8)
               << X[2][i] << endl;
   OutFile << "];" << endl;
   OutFile << "x3 = [" << endl;
   for (i = 1; i<= NoPoint; i++)
       OutFile << setw(8)
               << X[3][i] << endl;
   OutFile << "];" << endl;
   OutFile << "plot3(x1,x2,x3)" << endl;
   OutFile << "view([-120 10])" << endl;
   OutFile << "title ('"   << TitleB    << "')" << endl;
   OutFile << "xlabel('"   << XLabelB   << "')" << endl;
   OutFile << "ylabel('"   << YLabelB   << "')" << endl;
   OutFile << "zlabel('"   << ZLabelB   << "')" << endl;
   OutFile << "axis square;"
           << "grid on"    << endl;
   OutFile.close();
   cout    << "�w�g�s�� " << FileName2 << endl;
   return;
}
