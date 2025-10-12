/* ------------------------------------------------------------
copyright: "(c)Romain Michon, CCRMA (Stanford University), GRAME"
license: "MIT"
name: "FrenchChurchBell"
Code generated with Faust 2.33.1 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FrenchBellDsp_H__
#define  __FrenchBellDsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

const static float fFrenchBellDspSIG0Wave0[350] = {0.972890019f,0.542393029f,0.495831996f,0.897966027f,0.552366972f,0.557895005f,0.61421299f,0.353693992f,0.436039001f,0.441024005f,0.674912989f,0.566753983f,0.755007982f,0.699029982f,0.164398f,0.910040021f,0.628373027f,0.201718003f,0.429517001f,0.503714979f,0.871173978f,0.106885999f,0.76117301f,0.673601985f,0.291936994f,0.588590026f,0.31527999f,0.41308099f,0.274464011f,0.494062006f,0.696120977f,0.612010002f,0.382757008f,0.995113015f,0.228806004f,0.198449001f,0.595847011f,0.306263f,0.252397001f,0.0883567035f,0.236085996f,1.0f,0.245278001f,0.379388005f,0.198824003f,0.548892021f,0.492763996f,0.42087099f,0.794637024f,0.605633974f,1.0f,0.604158998f,0.399841011f,0.799346983f,0.507187009f,0.509809971f,0.477382988f,0.310225993f,0.426975995f,0.437622994f,0.735711992f,0.630728006f,0.625784993f,0.651167989f,0.277738005f,0.850857973f,0.578078985f,0.645353973f,0.383700013f,0.370597988f,0.78254199f,0.181325004f,0.614391029f,0.740683973f,0.342440993f,0.586185992f,0.286909014f,0.405196995f,0.259214997f,0.566982985f,0.748219013f,0.655897975f,0.368259996f,0.940814018f,0.336156994f,0.413702011f,0.561556995f,0.402175993f,0.117697999f,0.329369009f,0.254570991f,0.870706022f,0.260980994f,0.274122f,0.206247002f,0.645299971f,0.400757998f,0.36362201f,0.636834025f,0.584565997f,0.975602984f,0.616936982f,0.295401007f,0.650447011f,0.464221001f,0.465056986f,0.312467009f,0.238358006f,0.383695006f,0.399673998f,0.753911972f,0.662011981f,0.504267991f,0.599247992f,0.378665f,0.725363016f,0.493214011f,1.0f,0.332836002f,0.265888989f,0.674072981f,0.320401013f,0.440017998f,0.769782007f,0.316419005f,0.529968023f,0.380508989f,0.578675985f,0.249013007f,0.591383994f,0.761717021f,0.687057018f,0.324436992f,0.818863988f,0.505369008f,0.672484994f,0.461782992f,0.426198006f,0.0678874999f,0.43532899f,0.347954988f,0.708393991f,0.293321997f,0.328985989f,0.258253992f,0.893512011f,0.320131004f,0.433553994f,0.459302008f,0.542213023f,0.817241013f,0.516229987f,0.205302f,0.467354f,0.388682991f,0.388215989f,0.171261996f,0.150865003f,0.291720003f,0.311414003f,0.658876002f,0.570647001f,0.38361901f,0.502454996f,0.364113986f,0.532312989f,0.352988988f,1.0f,0.261983991f,0.219591007f,0.544031024f,0.337199003f,0.279172987f,0.668303013f,0.208439007f,0.399230003f,0.418673992f,0.648617983f,0.234133005f,0.504728973f,0.645346999f,0.572851002f,0.232828006f,0.614292026f,0.48527199f,0.666263998f,0.316570014f,0.320354998f,0.191421002f,0.340131015f,0.342069f,0.538371027f,0.281130999f,0.393115014f,0.251394004f,0.890725017f,0.310644001f,0.503700018f,0.299089998f,0.442478001f,0.733128011f,0.455217004f,0.199322f,0.315699011f,0.375856012f,0.376489997f,0.0291450005f,0.0200283006f,0.279578f,0.316799998f,0.655956984f,0.546842992f,0.349665999f,0.470248997f,0.353765011f,0.286794007f,0.180185005f,1.0f,0.210831001f,0.280133009f,0.535853028f,0.376488f,0.153669998f,0.634745002f,0.0510449f,0.485574991f,0.593110979f,0.917883992f,0.380477011f,0.422924995f,0.599372983f,0.311421007f,0.135654002f,0.359954f,0.295747995f,0.474438995f,0.353338987f,0.116742998f,0.45431301f,0.112857997f,0.359310001f,0.483897001f,0.301607996f,0.577341974f,0.262663007f,0.79498601f,0.549579978f,0.808085978f,0.152511001f,0.439590991f,0.535941005f,0.308017999f,0.419836998f,0.579191029f,0.250427991f,0.252119988f,0.102860004f,0.288331985f,0.599678993f,0.665108025f,0.636285007f,0.495234013f,0.251612991f,0.208526999f,0.0939071998f,0.458415002f,0.318951994f,0.235349998f,0.215188995f,0.313412011f,0.0472786985f,0.0386893004f,0.0863358974f,0.222345993f,0.361510992f,0.997036994f,0.238508999f,0.382140011f,1.0f,0.203554004f,0.472086996f,0.509015024f,0.206370994f,0.441013008f,0.794008017f,0.971623003f,0.796383977f,0.55043f,0.687780023f,0.554297984f,0.0436545014f,0.0595576987f,0.214684993f,0.581470013f,0.277319998f,0.36846599f,0.121381998f,0.152739003f,0.0782243982f,0.190496996f,0.31626901f,0.180455998f,0.405196011f,0.518715978f,0.159364998f,0.165808007f,0.194371998f,0.614763975f,0.553415f,0.644793987f,0.441780001f,0.441489995f,0.221588001f,1.0f,0.579370975f,0.606338978f,0.529166996f,0.0214475002f,0.41704601f,0.663151979f,0.894841015f,0.475751996f,0.168289006f,0.468589991f,0.304603994f,0.666369021f,0.308337003f,0.295091003f,0.768944979f,0.350910991f,0.490680009f,0.516583979f,0.40011701f,0.820686996f,0.545485973f,0.709357023f,0.509759009f,0.472005993f,0.152455002f,0.981265008f,0.459134012f,0.698665977f,0.247153997f,0.623252988f,0.255508006f,0.830815017f,0.0887089968f,0.126082003f,0.0770623013f,0.263327986f};
class FrenchBellDspSIG0 {
	
  private:
	
	int fFrenchBellDspSIG0Wave0_idx;
	
  public:
	
	int getNumInputsFrenchBellDspSIG0() {
		return 0;
	}
	int getNumOutputsFrenchBellDspSIG0() {
		return 1;
	}
	
	void instanceInitFrenchBellDspSIG0(int sample_rate) {
		fFrenchBellDspSIG0Wave0_idx = 0;
	}
	
	void fillFrenchBellDspSIG0(int count, float* table) {
		for (int i1 = 0; (i1 < count); i1 = (i1 + 1)) {
			table[i1] = fFrenchBellDspSIG0Wave0[fFrenchBellDspSIG0Wave0_idx];
			fFrenchBellDspSIG0Wave0_idx = ((1 + fFrenchBellDspSIG0Wave0_idx) % 350);
		}
	}

};

static FrenchBellDspSIG0* newFrenchBellDspSIG0() { return (FrenchBellDspSIG0*)new FrenchBellDspSIG0(); }
static void deleteFrenchBellDspSIG0(FrenchBellDspSIG0* dsp) { delete dsp; }

static float FrenchBellDsp_faustpower2_f(float value) {
	return (value * value);
}
static float ftbl0FrenchBellDspSIG0[350];

#ifndef FAUSTCLASS 
#define FAUSTCLASS FrenchBellDsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class FrenchBellDsp : public FaustDsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst4;
	float fConst6;
	int iRec3[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fRec2[3];
	float fRec1[3];
	float fConst10;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec4[2];
	float fConst12;
	float fConst13;
	float fRec0[3];
	FAUSTFLOAT fEntry0;
	float fConst15;
	float fConst16;
	float fRec5[3];
	float fConst18;
	float fConst19;
	float fRec6[3];
	float fConst21;
	float fConst22;
	float fRec7[3];
	float fConst24;
	float fConst25;
	float fRec8[3];
	float fConst27;
	float fConst28;
	float fRec9[3];
	float fConst30;
	float fConst31;
	float fRec10[3];
	float fConst33;
	float fConst34;
	float fRec11[3];
	float fConst36;
	float fConst37;
	float fRec12[3];
	float fConst39;
	float fConst40;
	float fRec13[3];
	float fConst42;
	float fConst43;
	float fRec14[3];
	float fConst45;
	float fConst46;
	float fRec15[3];
	float fConst48;
	float fConst49;
	float fRec16[3];
	float fConst51;
	float fConst52;
	float fRec17[3];
	float fConst54;
	float fConst55;
	float fRec18[3];
	float fConst57;
	float fConst58;
	float fRec19[3];
	float fConst60;
	float fConst61;
	float fRec20[3];
	float fConst63;
	float fConst64;
	float fRec21[3];
	float fConst66;
	float fConst67;
	float fRec22[3];
	float fConst69;
	float fConst70;
	float fRec23[3];
	float fConst72;
	float fConst73;
	float fRec24[3];
	float fConst75;
	float fConst76;
	float fRec25[3];
	float fConst78;
	float fConst79;
	float fRec26[3];
	float fConst81;
	float fConst82;
	float fRec27[3];
	float fConst84;
	float fConst85;
	float fRec28[3];
	float fConst87;
	float fConst88;
	float fRec29[3];
	float fConst90;
	float fConst91;
	float fRec30[3];
	float fConst93;
	float fConst94;
	float fRec31[3];
	float fConst96;
	float fConst97;
	float fRec32[3];
	float fConst99;
	float fConst100;
	float fRec33[3];
	float fConst102;
	float fConst103;
	float fRec34[3];
	float fConst105;
	float fConst106;
	float fRec35[3];
	float fConst108;
	float fConst109;
	float fRec36[3];
	float fConst111;
	float fConst112;
	float fRec37[3];
	float fConst114;
	float fConst115;
	float fRec38[3];
	float fConst117;
	float fConst118;
	float fRec39[3];
	float fConst120;
	float fConst121;
	float fRec40[3];
	float fConst123;
	float fConst124;
	float fRec41[3];
	float fConst126;
	float fConst127;
	float fRec42[3];
	float fConst129;
	float fConst130;
	float fRec43[3];
	float fConst132;
	float fConst133;
	float fRec44[3];
	float fConst135;
	float fConst136;
	float fRec45[3];
	float fConst138;
	float fConst139;
	float fRec46[3];
	float fConst141;
	float fConst142;
	float fRec47[3];
	float fConst144;
	float fConst145;
	float fRec48[3];
	float fConst147;
	float fConst148;
	float fRec49[3];
	float fConst150;
	float fConst151;
	float fRec50[3];
	float fConst153;
	float fConst154;
	float fRec51[3];
	float fConst156;
	float fConst157;
	float fRec52[3];
	float fConst159;
	float fConst160;
	float fRec53[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "(c)Romain Michon, CCRMA (Stanford University), GRAME");
		m->declare("description", "French church bell physical model.");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("filename", "frenchBell.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("license", "MIT");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.3");
		m->declare("name", "FrenchChurchBell");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		FrenchBellDspSIG0* sig0 = newFrenchBellDspSIG0();
		sig0->instanceInitFrenchBellDspSIG0(sample_rate);
		sig0->fillFrenchBellDspSIG0(350, ftbl0FrenchBellDspSIG0);
		deleteFrenchBellDspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (3.14159274f / fConst0);
		float fConst2 = std::tan((31.415926f / fConst0));
		float fConst3 = (1.0f / fConst2);
		fConst4 = (1.0f / (((fConst3 + 1.41421354f) / fConst2) + 1.0f));
		float fConst5 = FrenchBellDsp_faustpower2_f(fConst2);
		fConst6 = (0.0f - (2.0f / fConst5));
		fConst7 = (((fConst3 + -1.41421354f) / fConst2) + 1.0f);
		fConst8 = (1.0f / fConst5);
		fConst9 = (2.0f * (1.0f - fConst8));
		fConst10 = (0.00200000009f * fConst0);
		float fConst11 = std::pow(0.00100000005f, (36.6042595f / fConst0));
		fConst12 = (std::cos((14499.2041f / fConst0)) * (0.0f - (2.0f * fConst11)));
		fConst13 = FrenchBellDsp_faustpower2_f(fConst11);
		float fConst14 = std::pow(0.00100000005f, (32.6806145f / fConst0));
		fConst15 = (std::cos((14439.2627f / fConst0)) * (0.0f - (2.0f * fConst14)));
		fConst16 = FrenchBellDsp_faustpower2_f(fConst14);
		float fConst17 = std::pow(0.00100000005f, (13.9954367f / fConst0));
		fConst18 = (std::cos((13911.2861f / fConst0)) * (0.0f - (2.0f * fConst17)));
		fConst19 = FrenchBellDsp_faustpower2_f(fConst17);
		float fConst20 = std::pow(0.00100000005f, (7.07930517f / fConst0));
		fConst21 = (std::cos((13364.3984f / fConst0)) * (0.0f - (2.0f * fConst20)));
		fConst22 = FrenchBellDsp_faustpower2_f(fConst20);
		float fConst23 = std::pow(0.00100000005f, (6.55041027f / fConst0));
		fConst24 = (std::cos((13293.8379f / fConst0)) * (0.0f - (2.0f * fConst23)));
		fConst25 = FrenchBellDsp_faustpower2_f(fConst23);
		float fConst26 = std::pow(0.00100000005f, (5.13706398f / fConst0));
		fConst27 = (std::cos((13060.7949f / fConst0)) * (0.0f - (2.0f * fConst26)));
		fConst28 = FrenchBellDsp_faustpower2_f(fConst26);
		float fConst29 = std::pow(0.00100000005f, (3.95019245f / fConst0));
		fConst30 = (std::cos((12786.7217f / fConst0)) * (0.0f - (2.0f * fConst29)));
		fConst31 = FrenchBellDsp_faustpower2_f(fConst29);
		float fConst32 = std::pow(0.00100000005f, (2.24986076f / fConst0));
		fConst33 = (std::cos((12112.0967f / fConst0)) * (0.0f - (2.0f * fConst32)));
		fConst34 = FrenchBellDsp_faustpower2_f(fConst32);
		float fConst35 = std::pow(0.00100000005f, (2.07679749f / fConst0));
		fConst36 = (std::cos((12005.4707f / fConst0)) * (0.0f - (2.0f * fConst35)));
		fConst37 = FrenchBellDsp_faustpower2_f(fConst35);
		float fConst38 = std::pow(0.00100000005f, (1.56606674f / fConst0));
		fConst39 = (std::cos((11605.9229f / fConst0)) * (0.0f - (2.0f * fConst38)));
		fConst40 = FrenchBellDsp_faustpower2_f(fConst38);
		float fConst41 = std::pow(0.00100000005f, (1.39937711f / fConst0));
		fConst42 = (std::cos((11435.8369f / fConst0)) * (0.0f - (2.0f * fConst41)));
		fConst43 = FrenchBellDsp_faustpower2_f(fConst41);
		float fConst44 = std::pow(0.00100000005f, (1.3371644f / fConst0));
		fConst45 = (std::cos((11365.2773f / fConst0)) * (0.0f - (2.0f * fConst44)));
		fConst46 = FrenchBellDsp_faustpower2_f(fConst44);
		float fConst47 = std::pow(0.00100000005f, (1.31584406f / fConst0));
		fConst48 = (std::cos((11340.0811f / fConst0)) * (0.0f - (2.0f * fConst47)));
		fConst49 = FrenchBellDsp_faustpower2_f(fConst47);
		float fConst50 = std::pow(0.00100000005f, (0.792042196f / fConst0));
		fConst51 = (std::cos((10470.7402f / fConst0)) * (0.0f - (2.0f * fConst50)));
		fConst52 = FrenchBellDsp_faustpower2_f(fConst50);
		float fConst53 = std::pow(0.00100000005f, (0.869747579f / fConst0));
		fConst54 = (std::cos((10642.2705f / fConst0)) * (0.0f - (2.0f * fConst53)));
		fConst55 = FrenchBellDsp_faustpower2_f(fConst53);
		float fConst56 = std::pow(0.00100000005f, (0.862369478f / fConst0));
		fConst57 = (std::cos((10626.877f / fConst0)) * (0.0f - (2.0f * fConst56)));
		fConst58 = FrenchBellDsp_faustpower2_f(fConst56);
		float fConst59 = std::pow(0.00100000005f, (0.784023345f / fConst0));
		fConst60 = (std::cos((10451.7646f / fConst0)) * (0.0f - (2.0f * fConst59)));
		fConst61 = FrenchBellDsp_faustpower2_f(fConst59);
		float fConst62 = std::pow(0.00100000005f, (0.62480849f / fConst0));
		fConst63 = (std::cos((10011.3135f / fConst0)) * (0.0f - (2.0f * fConst62)));
		fConst64 = FrenchBellDsp_faustpower2_f(fConst62);
		float fConst65 = std::pow(0.00100000005f, (0.623096883f / fConst0));
		fConst66 = (std::cos((10005.7842f / fConst0)) * (0.0f - (2.0f * fConst65)));
		fConst67 = FrenchBellDsp_faustpower2_f(fConst65);
		float fConst68 = std::pow(0.00100000005f, (0.491248488f / fConst0));
		fConst69 = (std::cos((9506.83594f / fConst0)) * (0.0f - (2.0f * fConst68)));
		fConst70 = FrenchBellDsp_faustpower2_f(fConst68);
		float fConst71 = std::pow(0.00100000005f, (0.362907231f / fConst0));
		fConst72 = (std::cos((8811.35059f / fConst0)) * (0.0f - (2.0f * fConst71)));
		fConst73 = FrenchBellDsp_faustpower2_f(fConst71);
		float fConst74 = std::pow(0.00100000005f, (0.48983717f / fConst0));
		fConst75 = (std::cos((9500.55273f / fConst0)) * (0.0f - (2.0f * fConst74)));
		fConst76 = FrenchBellDsp_faustpower2_f(fConst74);
		float fConst77 = std::pow(0.00100000005f, (0.223363191f / fConst0));
		fConst78 = (std::cos((7539.25684f / fConst0)) * (0.0f - (2.0f * fConst77)));
		fConst79 = FrenchBellDsp_faustpower2_f(fConst77);
		float fConst80 = std::pow(0.00100000005f, (0.36082828f / fConst0));
		fConst81 = (std::cos((8797.46484f / fConst0)) * (0.0f - (2.0f * fConst80)));
		fConst82 = FrenchBellDsp_faustpower2_f(fConst80);
		float fConst83 = std::pow(0.00100000005f, (0.349399418f / fConst0));
		fConst84 = (std::cos((8719.17578f / fConst0)) * (0.0f - (2.0f * fConst83)));
		fConst85 = FrenchBellDsp_faustpower2_f(fConst83);
		float fConst86 = std::pow(0.00100000005f, (0.199929953f / fConst0));
		fConst87 = (std::cos((7218.75146f / fConst0)) * (0.0f - (2.0f * fConst86)));
		fConst88 = FrenchBellDsp_faustpower2_f(fConst86);
		float fConst89 = std::pow(0.00100000005f, (0.22197479f / fConst0));
		fConst90 = (std::cos((7521.53809f / fConst0)) * (0.0f - (2.0f * fConst89)));
		fConst91 = FrenchBellDsp_faustpower2_f(fConst89);
		float fConst92 = std::pow(0.00100000005f, (0.172007188f / fConst0));
		fConst93 = (std::cos((6764.35156f / fConst0)) * (0.0f - (2.0f * fConst92)));
		fConst94 = FrenchBellDsp_faustpower2_f(fConst92);
		float fConst95 = std::pow(0.00100000005f, (0.198453143f / fConst0));
		fConst96 = (std::cos((7196.88623f / fConst0)) * (0.0f - (2.0f * fConst95)));
		fConst97 = FrenchBellDsp_faustpower2_f(fConst95);
		float fConst98 = std::pow(0.00100000005f, (0.17125909f / fConst0));
		fConst99 = (std::cos((6750.84277f / fConst0)) * (0.0f - (2.0f * fConst98)));
		fConst100 = FrenchBellDsp_faustpower2_f(fConst98);
		float fConst101 = std::pow(0.00100000005f, (0.170774281f / fConst0));
		fConst102 = (std::cos((6742.04639f / fConst0)) * (0.0f - (2.0f * fConst101)));
		fConst103 = FrenchBellDsp_faustpower2_f(fConst101);
		float fConst104 = std::pow(0.00100000005f, (0.167944118f / fConst0));
		fConst105 = (std::cos((6690.02148f / fConst0)) * (0.0f - (2.0f * fConst104)));
		fConst106 = FrenchBellDsp_faustpower2_f(fConst104);
		float fConst107 = std::pow(0.00100000005f, (0.122413002f / fConst0));
		fConst108 = (std::cos((5648.90381f / fConst0)) * (0.0f - (2.0f * fConst107)));
		fConst109 = FrenchBellDsp_faustpower2_f(fConst107);
		float fConst110 = std::pow(0.00100000005f, (0.16781573f / fConst0));
		fConst111 = (std::cos((6687.63379f / fConst0)) * (0.0f - (2.0f * fConst110)));
		fConst112 = FrenchBellDsp_faustpower2_f(fConst110);
		float fConst113 = std::pow(0.00100000005f, (0.0884945765f / fConst0));
		fConst114 = (std::cos((4460.28857f / fConst0)) * (0.0f - (2.0f * fConst113)));
		fConst115 = FrenchBellDsp_faustpower2_f(fConst113);
		float fConst116 = std::pow(0.00100000005f, (0.113536403f / fConst0));
		fConst117 = (std::cos((5384.47607f / fConst0)) * (0.0f - (2.0f * fConst116)));
		fConst118 = FrenchBellDsp_faustpower2_f(fConst116);
		float fConst119 = std::pow(0.00100000005f, (0.0751398876f / fConst0));
		fConst120 = (std::cos((3810.4502f / fConst0)) * (0.0f - (2.0f * fConst119)));
		fConst121 = FrenchBellDsp_faustpower2_f(fConst119);
		float fConst122 = std::pow(0.00100000005f, (0.075759083f / fConst0));
		fConst123 = (std::cos((3843.90186f / fConst0)) * (0.0f - (2.0f * fConst122)));
		fConst124 = FrenchBellDsp_faustpower2_f(fConst122);
		float fConst125 = std::pow(0.00100000005f, (0.088457182f / fConst0));
		fConst126 = (std::cos((4458.65527f / fConst0)) * (0.0f - (2.0f * fConst125)));
		fConst127 = FrenchBellDsp_faustpower2_f(fConst125);
		float fConst128 = std::pow(0.00100000005f, (0.0587863363f / fConst0));
		fConst129 = (std::cos((2766.51782f / fConst0)) * (0.0f - (2.0f * fConst128)));
		fConst130 = FrenchBellDsp_faustpower2_f(fConst128);
		float fConst131 = std::pow(0.00100000005f, (0.0586840585f / fConst0));
		fConst132 = (std::cos((2758.80225f / fConst0)) * (0.0f - (2.0f * fConst131)));
		fConst133 = FrenchBellDsp_faustpower2_f(fConst131);
		float fConst134 = std::pow(0.00100000005f, (4.03475237f / fConst0));
		fConst135 = (std::cos((12809.7188f / fConst0)) * (0.0f - (2.0f * fConst134)));
		fConst136 = FrenchBellDsp_faustpower2_f(fConst134);
		float fConst137 = std::pow(0.00100000005f, (4.43228626f / fConst0));
		fConst138 = (std::cos((12909.8096f / fConst0)) * (0.0f - (2.0f * fConst137)));
		fConst139 = FrenchBellDsp_faustpower2_f(fConst137);
		float fConst140 = std::pow(0.00100000005f, (4.45921993f / fConst0));
		fConst141 = (std::cos((12916.1553f / fConst0)) * (0.0f - (2.0f * fConst140)));
		fConst142 = FrenchBellDsp_faustpower2_f(fConst140);
		float fConst143 = std::pow(0.00100000005f, (5.58396626f / fConst0));
		fConst144 = (std::cos((13142.916f / fConst0)) * (0.0f - (2.0f * fConst143)));
		fConst145 = FrenchBellDsp_faustpower2_f(fConst143);
		float fConst146 = std::pow(0.00100000005f, (13.4923172f / fConst0));
		fConst147 = (std::cos((13884.96f / fConst0)) * (0.0f - (2.0f * fConst146)));
		fConst148 = FrenchBellDsp_faustpower2_f(fConst146);
		float fConst149 = std::pow(0.00100000005f, (31.9558811f / fConst0));
		fConst150 = (std::cos((14427.1357f / fConst0)) * (0.0f - (2.0f * fConst149)));
		fConst151 = FrenchBellDsp_faustpower2_f(fConst149);
		float fConst152 = std::pow(0.00100000005f, (33.0222092f / fConst0));
		fConst153 = (std::cos((14444.8545f / fConst0)) * (0.0f - (2.0f * fConst152)));
		fConst154 = FrenchBellDsp_faustpower2_f(fConst152);
		float fConst155 = std::pow(0.00100000005f, (161.987732f / fConst0));
		fConst156 = (std::cos((15107.542f / fConst0)) * (0.0f - (2.0f * fConst155)));
		fConst157 = FrenchBellDsp_faustpower2_f(fConst155);
		float fConst158 = std::pow(0.00100000005f, (177.575241f / fConst0));
		fConst159 = (std::cos((15136.1309f / fConst0)) * (0.0f - (2.0f * fConst158)));
		fConst160 = FrenchBellDsp_faustpower2_f(fConst158);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(6500.0f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec3[l0] = 0;
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec0[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			iRec4[l4] = 0;
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec0[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec8[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec13[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec14[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec16[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec17[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec20[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) {
			fRec23[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec24[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec25[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec26[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) {
			fRec27[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec28[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec29[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec30[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) {
			fRec31[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec32[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec33[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec34[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec35[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec36[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec37[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 3); l39 = (l39 + 1)) {
			fRec38[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 3); l40 = (l40 + 1)) {
			fRec39[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec40[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 3); l42 = (l42 + 1)) {
			fRec41[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) {
			fRec42[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 3); l44 = (l44 + 1)) {
			fRec43[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 3); l45 = (l45 + 1)) {
			fRec44[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 3); l46 = (l46 + 1)) {
			fRec45[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 3); l47 = (l47 + 1)) {
			fRec46[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec47[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 3); l49 = (l49 + 1)) {
			fRec48[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec49[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec50[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec51[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec52[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec53[l54] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual FrenchBellDsp* clone() {
		return new FrenchBellDsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("frenchBell");
		ui_interface->declare(&fEntry0, "0", "");
		ui_interface->addNumEntry("strikePosition", &fEntry0, 0.0f, 0.0f, 4.0f, 1.0f);
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("strikeCutOff", &fHslider1, 6500.0f, 20.0f, 20000.0f, 1.0f);
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->addHorizontalSlider("strikeSharpness", &fHslider2, 0.5f, 0.00999999978f, 5.0f, 0.00999999978f);
		ui_interface->declare(&fHslider0, "3", "");
		ui_interface->addHorizontalSlider("gain", &fHslider0, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fButton0, "4", "");
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::tan((fConst1 * float(fHslider1)));
		float fSlow1 = (1.0f / fSlow0);
		float fSlow2 = (((fSlow1 + 1.41421354f) / fSlow0) + 1.0f);
		float fSlow3 = (float(fHslider0) / fSlow2);
		float fSlow4 = (1.0f / fSlow2);
		float fSlow5 = (((fSlow1 + -1.41421354f) / fSlow0) + 1.0f);
		float fSlow6 = (2.0f * (1.0f - (1.0f / FrenchBellDsp_faustpower2_f(fSlow0))));
		float fSlow7 = (1.0f / std::max<float>(1.0f, (fConst10 * float(fHslider2))));
		float fSlow8 = float(fButton0);
		int iSlow9 = (50 * int(float(fEntry0)));
		float fSlow10 = ftbl0FrenchBellDspSIG0[(iSlow9 + 47)];
		float fSlow11 = ftbl0FrenchBellDspSIG0[(iSlow9 + 45)];
		float fSlow12 = ftbl0FrenchBellDspSIG0[(iSlow9 + 43)];
		float fSlow13 = ftbl0FrenchBellDspSIG0[(iSlow9 + 41)];
		float fSlow14 = ftbl0FrenchBellDspSIG0[(iSlow9 + 40)];
		float fSlow15 = ftbl0FrenchBellDspSIG0[(iSlow9 + 38)];
		float fSlow16 = ftbl0FrenchBellDspSIG0[(iSlow9 + 34)];
		float fSlow17 = ftbl0FrenchBellDspSIG0[(iSlow9 + 33)];
		float fSlow18 = ftbl0FrenchBellDspSIG0[(iSlow9 + 32)];
		float fSlow19 = ftbl0FrenchBellDspSIG0[(iSlow9 + 31)];
		float fSlow20 = ftbl0FrenchBellDspSIG0[(iSlow9 + 30)];
		float fSlow21 = ftbl0FrenchBellDspSIG0[(iSlow9 + 29)];
		float fSlow22 = ftbl0FrenchBellDspSIG0[(iSlow9 + 28)];
		float fSlow23 = ftbl0FrenchBellDspSIG0[(iSlow9 + 25)];
		float fSlow24 = ftbl0FrenchBellDspSIG0[(iSlow9 + 27)];
		float fSlow25 = ftbl0FrenchBellDspSIG0[(iSlow9 + 26)];
		float fSlow26 = ftbl0FrenchBellDspSIG0[(iSlow9 + 24)];
		float fSlow27 = ftbl0FrenchBellDspSIG0[(iSlow9 + 23)];
		float fSlow28 = ftbl0FrenchBellDspSIG0[(iSlow9 + 22)];
		float fSlow29 = ftbl0FrenchBellDspSIG0[(iSlow9 + 21)];
		float fSlow30 = ftbl0FrenchBellDspSIG0[(iSlow9 + 19)];
		float fSlow31 = ftbl0FrenchBellDspSIG0[(iSlow9 + 20)];
		float fSlow32 = ftbl0FrenchBellDspSIG0[(iSlow9 + 16)];
		float fSlow33 = ftbl0FrenchBellDspSIG0[(iSlow9 + 18)];
		float fSlow34 = ftbl0FrenchBellDspSIG0[(iSlow9 + 17)];
		float fSlow35 = ftbl0FrenchBellDspSIG0[(iSlow9 + 14)];
		float fSlow36 = ftbl0FrenchBellDspSIG0[(iSlow9 + 15)];
		float fSlow37 = ftbl0FrenchBellDspSIG0[(iSlow9 + 12)];
		float fSlow38 = ftbl0FrenchBellDspSIG0[(iSlow9 + 13)];
		float fSlow39 = ftbl0FrenchBellDspSIG0[(iSlow9 + 11)];
		float fSlow40 = ftbl0FrenchBellDspSIG0[(iSlow9 + 10)];
		float fSlow41 = ftbl0FrenchBellDspSIG0[(iSlow9 + 9)];
		float fSlow42 = ftbl0FrenchBellDspSIG0[(iSlow9 + 7)];
		float fSlow43 = ftbl0FrenchBellDspSIG0[(iSlow9 + 8)];
		float fSlow44 = ftbl0FrenchBellDspSIG0[(iSlow9 + 5)];
		float fSlow45 = ftbl0FrenchBellDspSIG0[(iSlow9 + 6)];
		float fSlow46 = ftbl0FrenchBellDspSIG0[(iSlow9 + 2)];
		float fSlow47 = ftbl0FrenchBellDspSIG0[(iSlow9 + 3)];
		float fSlow48 = ftbl0FrenchBellDspSIG0[(iSlow9 + 4)];
		float fSlow49 = ftbl0FrenchBellDspSIG0[(iSlow9 + 1)];
		float fSlow50 = ftbl0FrenchBellDspSIG0[iSlow9];
		float fSlow51 = ftbl0FrenchBellDspSIG0[(iSlow9 + 35)];
		float fSlow52 = ftbl0FrenchBellDspSIG0[(iSlow9 + 36)];
		float fSlow53 = ftbl0FrenchBellDspSIG0[(iSlow9 + 37)];
		float fSlow54 = ftbl0FrenchBellDspSIG0[(iSlow9 + 39)];
		float fSlow55 = ftbl0FrenchBellDspSIG0[(iSlow9 + 42)];
		float fSlow56 = ftbl0FrenchBellDspSIG0[(iSlow9 + 44)];
		float fSlow57 = ftbl0FrenchBellDspSIG0[(iSlow9 + 46)];
		float fSlow58 = ftbl0FrenchBellDspSIG0[(iSlow9 + 48)];
		float fSlow59 = ftbl0FrenchBellDspSIG0[(iSlow9 + 49)];
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iRec3[0] = (((1103515245 * iRec3[1]) & 2147483647) + 12345);
			fRec2[0] = ((4.65661287e-10f * float(iRec3[0])) - (fConst4 * ((fConst7 * fRec2[2]) + (fConst9 * fRec2[1]))));
			fRec1[0] = ((fConst4 * (((fConst6 * fRec2[1]) + (fConst8 * fRec2[0])) + (fConst8 * fRec2[2]))) - (fSlow4 * ((fSlow5 * fRec1[2]) + (fSlow6 * fRec1[1]))));
			fVec0[0] = fSlow8;
			iRec4[0] = (((iRec4[1] + (iRec4[1] > 0)) * (fSlow8 <= fVec0[1])) + (fSlow8 > fVec0[1]));
			float fTemp0 = (fSlow7 * float(iRec4[0]));
			float fTemp1 = (fSlow3 * ((fRec1[2] + (fRec1[0] + (2.0f * fRec1[1]))) * std::max<float>(0.0f, std::min<float>(fTemp0, (2.0f - fTemp0)))));
			fRec0[0] = (fTemp1 - ((fConst12 * fRec0[1]) + (fConst13 * fRec0[2])));
			fRec5[0] = (fTemp1 - ((fConst15 * fRec5[1]) + (fConst16 * fRec5[2])));
			fRec6[0] = (fTemp1 - ((fConst18 * fRec6[1]) + (fConst19 * fRec6[2])));
			fRec7[0] = (fTemp1 - ((fConst21 * fRec7[1]) + (fConst22 * fRec7[2])));
			fRec8[0] = (fTemp1 - ((fConst24 * fRec8[1]) + (fConst25 * fRec8[2])));
			fRec9[0] = (fTemp1 - ((fConst27 * fRec9[1]) + (fConst28 * fRec9[2])));
			fRec10[0] = (fTemp1 - ((fConst30 * fRec10[1]) + (fConst31 * fRec10[2])));
			fRec11[0] = (fTemp1 - ((fConst33 * fRec11[1]) + (fConst34 * fRec11[2])));
			fRec12[0] = (fTemp1 - ((fConst36 * fRec12[1]) + (fConst37 * fRec12[2])));
			fRec13[0] = (fTemp1 - ((fConst39 * fRec13[1]) + (fConst40 * fRec13[2])));
			fRec14[0] = (fTemp1 - ((fConst42 * fRec14[1]) + (fConst43 * fRec14[2])));
			fRec15[0] = (fTemp1 - ((fConst45 * fRec15[1]) + (fConst46 * fRec15[2])));
			fRec16[0] = (fTemp1 - ((fConst48 * fRec16[1]) + (fConst49 * fRec16[2])));
			fRec17[0] = (fTemp1 - ((fConst51 * fRec17[1]) + (fConst52 * fRec17[2])));
			fRec18[0] = (fTemp1 - ((fConst54 * fRec18[1]) + (fConst55 * fRec18[2])));
			fRec19[0] = (fTemp1 - ((fConst57 * fRec19[1]) + (fConst58 * fRec19[2])));
			fRec20[0] = (fTemp1 - ((fConst60 * fRec20[1]) + (fConst61 * fRec20[2])));
			fRec21[0] = (fTemp1 - ((fConst63 * fRec21[1]) + (fConst64 * fRec21[2])));
			fRec22[0] = (fTemp1 - ((fConst66 * fRec22[1]) + (fConst67 * fRec22[2])));
			fRec23[0] = (fTemp1 - ((fConst69 * fRec23[1]) + (fConst70 * fRec23[2])));
			fRec24[0] = (fTemp1 - ((fConst72 * fRec24[1]) + (fConst73 * fRec24[2])));
			fRec25[0] = (fTemp1 - ((fConst75 * fRec25[1]) + (fConst76 * fRec25[2])));
			fRec26[0] = (fTemp1 - ((fConst78 * fRec26[1]) + (fConst79 * fRec26[2])));
			fRec27[0] = (fTemp1 - ((fConst81 * fRec27[1]) + (fConst82 * fRec27[2])));
			fRec28[0] = (fTemp1 - ((fConst84 * fRec28[1]) + (fConst85 * fRec28[2])));
			fRec29[0] = (fTemp1 - ((fConst87 * fRec29[1]) + (fConst88 * fRec29[2])));
			fRec30[0] = (fTemp1 - ((fConst90 * fRec30[1]) + (fConst91 * fRec30[2])));
			fRec31[0] = (fTemp1 - ((fConst93 * fRec31[1]) + (fConst94 * fRec31[2])));
			fRec32[0] = (fTemp1 - ((fConst96 * fRec32[1]) + (fConst97 * fRec32[2])));
			fRec33[0] = (fTemp1 - ((fConst99 * fRec33[1]) + (fConst100 * fRec33[2])));
			fRec34[0] = (fTemp1 - ((fConst102 * fRec34[1]) + (fConst103 * fRec34[2])));
			fRec35[0] = (fTemp1 - ((fConst105 * fRec35[1]) + (fConst106 * fRec35[2])));
			fRec36[0] = (fTemp1 - ((fConst108 * fRec36[1]) + (fConst109 * fRec36[2])));
			fRec37[0] = (fTemp1 - ((fConst111 * fRec37[1]) + (fConst112 * fRec37[2])));
			fRec38[0] = (fTemp1 - ((fConst114 * fRec38[1]) + (fConst115 * fRec38[2])));
			fRec39[0] = (fTemp1 - ((fConst117 * fRec39[1]) + (fConst118 * fRec39[2])));
			fRec40[0] = (fTemp1 - ((fConst120 * fRec40[1]) + (fConst121 * fRec40[2])));
			fRec41[0] = (fTemp1 - ((fConst123 * fRec41[1]) + (fConst124 * fRec41[2])));
			fRec42[0] = (fTemp1 - ((fConst126 * fRec42[1]) + (fConst127 * fRec42[2])));
			fRec43[0] = (fTemp1 - ((fConst129 * fRec43[1]) + (fConst130 * fRec43[2])));
			fRec44[0] = (fTemp1 - ((fConst132 * fRec44[1]) + (fConst133 * fRec44[2])));
			fRec45[0] = (fTemp1 - ((fConst135 * fRec45[1]) + (fConst136 * fRec45[2])));
			fRec46[0] = (fTemp1 - ((fConst138 * fRec46[1]) + (fConst139 * fRec46[2])));
			fRec47[0] = (fTemp1 - ((fConst141 * fRec47[1]) + (fConst142 * fRec47[2])));
			fRec48[0] = (fTemp1 - ((fConst144 * fRec48[1]) + (fConst145 * fRec48[2])));
			fRec49[0] = (fTemp1 - ((fConst147 * fRec49[1]) + (fConst148 * fRec49[2])));
			fRec50[0] = (fTemp1 - ((fConst150 * fRec50[1]) + (fConst151 * fRec50[2])));
			fRec51[0] = (fTemp1 - ((fConst153 * fRec51[1]) + (fConst154 * fRec51[2])));
			fRec52[0] = (fTemp1 - ((fConst156 * fRec52[1]) + (fConst157 * fRec52[2])));
			fRec53[0] = (fTemp1 - ((fConst159 * fRec53[1]) + (fConst160 * fRec53[2])));
			float fTemp2 = (0.0199999996f * (((fRec0[0] - fRec0[2]) * fSlow10) + (((((fRec5[0] - fRec5[2]) * fSlow11) + ((((fRec6[0] - fRec6[2]) * fSlow12) + ((((fRec7[0] - fRec7[2]) * fSlow13) + (((fRec8[0] - fRec8[2]) * fSlow14) + ((((fRec9[0] - fRec9[2]) * fSlow15) + ((((((fRec10[0] - fRec10[2]) * fSlow16) + (((fRec11[0] - fRec11[2]) * fSlow17) + (((fRec12[0] - fRec12[2]) * fSlow18) + (((fRec13[0] - fRec13[2]) * fSlow19) + (((fRec14[0] - fRec14[2]) * fSlow20) + (((fRec15[0] - fRec15[2]) * fSlow21) + (((fRec16[0] - fRec16[2]) * fSlow22) + (((fRec17[0] - fRec17[2]) * fSlow23) + (((fRec18[0] - fRec18[2]) * fSlow24) + (((fRec19[0] - fRec19[2]) * fSlow25) + (((fRec20[0] - fRec20[2]) * fSlow26) + (((fRec21[0] - fRec21[2]) * fSlow27) + (((fRec22[0] - fRec22[2]) * fSlow28) + (((fRec23[0] - fRec23[2]) * fSlow29) + (((fRec24[0] - fRec24[2]) * fSlow30) + (((fRec25[0] - fRec25[2]) * fSlow31) + (((fRec26[0] - fRec26[2]) * fSlow32) + (((fRec27[0] - fRec27[2]) * fSlow33) + (((fRec28[0] - fRec28[2]) * fSlow34) + (((fRec29[0] - fRec29[2]) * fSlow35) + (((fRec30[0] - fRec30[2]) * fSlow36) + (((fRec31[0] - fRec31[2]) * fSlow37) + (((fRec32[0] - fRec32[2]) * fSlow38) + (((fRec33[0] - fRec33[2]) * fSlow39) + (((fRec34[0] - fRec34[2]) * fSlow40) + (((fRec35[0] - fRec35[2]) * fSlow41) + (((fRec36[0] - fRec36[2]) * fSlow42) + (((fRec37[0] - fRec37[2]) * fSlow43) + (((fRec38[0] - fRec38[2]) * fSlow44) + (((fRec39[0] - fRec39[2]) * fSlow45) + (((fRec40[0] - fRec40[2]) * fSlow46) + (((fRec41[0] - fRec41[2]) * fSlow47) + (((fRec42[0] - fRec42[2]) * fSlow48) + (((fRec43[0] - fRec43[2]) * fSlow49) + (((fRec44[0] - fRec44[2]) * fSlow50) + ((fRec45[0] - fRec45[2]) * fSlow51)))))))))))))))))))))))))))))))))))) + ((fRec46[0] - fRec46[2]) * fSlow52)) + ((fRec47[0] - fRec47[2]) * fSlow53)) + ((fRec48[0] - fRec48[2]) * fSlow54))) + ((fRec49[0] - fRec49[2]) * fSlow55)))) + ((fRec50[0] - fRec50[2]) * fSlow56))) + ((fRec51[0] - fRec51[2]) * fSlow57))) + ((fRec52[0] - fRec52[2]) * fSlow58)) + ((fRec53[0] - fRec53[2]) * fSlow59))));
			output0[i0] = FAUSTFLOAT(fTemp2);
			output1[i0] = FAUSTFLOAT(fTemp2);
			iRec3[1] = iRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
			iRec4[1] = iRec4[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fRec29[2] = fRec29[1];
			fRec29[1] = fRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fRec48[2] = fRec48[1];
			fRec48[1] = fRec48[0];
			fRec49[2] = fRec49[1];
			fRec49[1] = fRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fRec51[2] = fRec51[1];
			fRec51[1] = fRec51[0];
			fRec52[2] = fRec52[1];
			fRec52[1] = fRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
		}
	}

};

#endif
