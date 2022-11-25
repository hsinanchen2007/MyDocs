// MPlot.cpp
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// 本程式版權屬於 張耀仁
// 使用時必需聲明.
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
               << X[3][i] << endl;
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
// 定義函數 XYZPlot() 以自動產生 MATLAB 的 3D 繪圖指令void XYZPlot(Matrix& X)
void XYZPlot(Matrix& X)
{
   int i;
   fstream OutFile(FileName2, ios::out);
   if (!OutFile) {cout<< "File: " << FileName2
      << "存檔失敗!" << endl; exit(1);}
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
   cout    << "已經存於 " << FileName2 << endl;
   return;
}
