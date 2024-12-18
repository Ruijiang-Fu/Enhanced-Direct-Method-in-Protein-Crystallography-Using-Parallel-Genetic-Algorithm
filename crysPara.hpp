#define PDB_CODE_REFE_HIST 	"6g6e"
#define PDB_CODE "6eik"

//cell parameters
#define CRYST_A 62.210
#define CRYST_B 62.210
#define CRYST_C 108.680
#define CRYST_ALPHA ( 90.00 / 180.00 * PI )
#define CRYST_BETA  ( 90.00 / 180.00 * PI )
#define CRYST_GAMMA ( 90.00 / 180.00 * PI )

//grid size
#define ANUM 246 //mod(ANUM,2)==0
#define BNUM 246 //mod(BNUM,2)==0
#define CNUM 144 //mod(CNUM,2)==0 for P42212

using namespace std;

const float resoCutoff = 1.52;
const float resoCutoffLow = 12.0;

const float solvContIni = 0.38; //sfcheck 21.3% pdb matthews 39.72%
const float solvContFina = 0.38;
float solvCont = solvContIni;

//weighted observed data
const float sigmWeigObsIni = 1.0;
float sigmWeigObs = sigmWeigObsIni;

//weighted average density
const float sigmWeigAvgIni = 2.5;
const float sigmWeigAvgFina = 2.5;
float sigmWeigAvg = sigmWeigAvgIni;
char updateSpeedWeigAvgDens[] = "normally"; 
//"normally" 100%; "slowly" 50% + 50%; "very slowly" 5% + 95%; "extremely slowly" 1% + 99%

const int numIter = 10000;

//MPI
const int numCrossPosi = 11;
const float crossGenePercent = 0.05; //percent of ASU for each crossover position
const float mutateGenePercent = 0.01; //percent of ASU for mutation

const float goodProtMaskThreshold = 0.90; //protMaskMatch > threshold
const float convThreshold = 70.0; //meanPhaseError < threshold

#define NCSANUM 260
#define NCSBNUM 260
#define NCSCNUM 200

//sigma of weighting function
const float sigmWeigNcs = 4.0;

//sigma of weighting function for updating centMassOrth
const float sigmWeigCentMass = 15.0;

const int numNcsOper = 7;
float ncsOper[numNcsOper][3][4] = 
{  	{ { 1.0, 0.0, 0.0, 0.0 }, 
	  { 0.0, 1.0, 0.0, 0.0 }, 
	  { 0.0, 0.0, 1.0, 0.0 } }, 
	{ { -0.2094,  0.8364, -0.5066,  51.1571},
	  { -0.6932, -0.4923, -0.5263, 141.5947},
	  { -0.6896,  0.2410,  0.6829,  42.6693} } };

const int numCentMass = 1;
const float centMassOrthTrue[numCentMass][3] = {43.376, 43.274, 77.496}; //center of molecule
float centMassOrth[numCentMass][3] = {43.376, 43.274, 77.496}; 

const float pointAOnNcsAxisTrue[3] = {43.376, 43.274, 77.496};
const float vectOnNcsAxisTrue[3] = {0.032,0.078,-17.958}; 
float pointAOnNcsAxis[3] = {43.392, 43.313, 68.517};
float pointBOnNcsAxis[3] = {43.360, 43.235, 86.475};
float vectOnNcsAxis[3] = {0.032,0.078,-17.958}; 

//self-rotation function at section kappa: lateral angle psi; azimuthal angle phi.
const float kappa = 180.0 / 180.0 * 3.1415926;
const float lateAnglPsi = 26.0 / 180.0 * 3.1415926;
const float azimAnglPhi = -175.0 / 180.0 * 3.1415926; //+-5 deg, and +-175 deg
//const float vectOnNcsAxisIni[3] = {-0.43670, -0.03821, 0.89879};

const int numNcsAxisCand = 101;//candNcsAxis + initNcsAxis

const float ncsAxisDeviDistMax = 10.0;	//10 angstroms
const float ncsAxisDeviAnglMax = 10.0 / 180.0 * 3.1415926; //10 degrees

const float rotaNcsAngl = (360.0/7.0) / 180.0 * 3.1415926;
const bool rotaNcsFlag = true;
const bool tranNcsFlag = false;
const float tranNcsDist = 0;

#include "../header/commPara.hpp"
#include "../header/P42212.hpp"

