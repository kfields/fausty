/* ------------------------------------------------------------
name: "chain"
Code generated with Faust 2.33.1 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __ChainDsp_H__
#define  __ChainDsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float ChainDsp_faustpower2_f(float value) {
	return (value * value);
}
static float ChainDsp_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float ChainDsp_faustpower4_f(float value) {
	return (((value * value) * value) * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS ChainDsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class ChainDsp : public FaustDsp {
	
 private:
	
	int fSampleRate;
	float fConst1;
	FAUSTFLOAT fVslider0;
	float fConst2;
	int iVec0[2];
	float fRec0[2];
	FAUSTFLOAT fVslider1;
	float fRec1[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	FAUSTFLOAT fHslider3;
	float fRec9[2];
	float fVec1[2];
	float fRec7[2];
	float fConst3;
	FAUSTFLOAT fHslider4;
	float fRec10[2];
	float fRec6[2];
	float fRec5[2];
	float fRec4[2];
	float fRec3[2];
	float fRec2[2];
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fHslider5;
	float fConst4;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	float fRec16[2];
	float fRec17[2];
	float fRec15[3];
	float fRec14[3];
	float fRec13[3];
	float fRec12[3];
	float fRec11[2];
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fHslider13;
	float fRec25[3];
	float fRec24[3];
	float fRec23[3];
	float fRec22[3];
	float fRec21[2];
	FAUSTFLOAT fHslider14;
	float fRec20[2];
	float fRec19[2];
	FAUSTFLOAT fHslider15;
	float fRec18[2];
	int IOTA;
	float fVec2[16384];
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT fVslider3;
	float fConst6;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	FAUSTFLOAT fVslider6;
	float fConst7;
	FAUSTFLOAT fVslider7;
	float fRec38[2];
	float fRec37[2];
	float fVec3[32768];
	int iConst9;
	float fRec41[2];
	float fRec40[2];
	float fRec39[2];
	FAUSTFLOAT fHbargraph0;
	float fVec4[16384];
	float fConst10;
	FAUSTFLOAT fVslider8;
	float fVec5[2048];
	int iConst11;
	float fRec35[2];
	float fConst13;
	float fRec45[2];
	float fRec44[2];
	float fVec6[32768];
	int iConst15;
	float fVec7[4096];
	int iConst16;
	float fRec42[2];
	float fConst18;
	float fRec49[2];
	float fRec48[2];
	float fVec8[16384];
	int iConst20;
	float fVec9[4096];
	int iConst21;
	float fRec46[2];
	float fConst23;
	float fRec53[2];
	float fRec52[2];
	float fVec10[32768];
	int iConst25;
	float fVec11[4096];
	int iConst26;
	float fRec50[2];
	float fConst28;
	float fRec57[2];
	float fRec56[2];
	float fVec12[16384];
	int iConst30;
	float fVec13[4096];
	int iConst31;
	float fRec54[2];
	float fConst33;
	float fRec61[2];
	float fRec60[2];
	float fVec14[16384];
	int iConst35;
	float fVec15[4096];
	int iConst36;
	float fRec58[2];
	float fConst38;
	float fRec65[2];
	float fRec64[2];
	float fVec16[16384];
	int iConst40;
	float fVec17[2048];
	int iConst41;
	float fRec62[2];
	float fConst43;
	float fRec69[2];
	float fRec68[2];
	float fVec18[16384];
	int iConst45;
	float fVec19[2048];
	int iConst46;
	float fRec66[2];
	float fRec27[3];
	float fRec28[3];
	float fRec29[3];
	float fRec30[3];
	float fRec31[3];
	float fRec32[3];
	float fRec33[3];
	float fRec34[3];
	float fRec26[3];
	FAUSTFLOAT fVslider9;
	FAUSTFLOAT fVslider10;
	float fRec70[3];
	float fRec71[3];
	float fRec72[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_stereo:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_stereo:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_stereo:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "0.1");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("filename", "chain.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/peak_eq_rm:author", "Julius O. Smith III");
		m->declare("filters.lib/peak_eq_rm:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/peak_eq_rm:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "chain");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "0.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("vaeffects.lib/moog_vcf:author", "Julius O. Smith III");
		m->declare("vaeffects.lib/moog_vcf:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("vaeffects.lib/moog_vcf:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (44.0999985f / fConst0);
		fConst2 = (1.0f - fConst1);
		fConst3 = (6.28318548f / fConst0);
		fConst4 = (1.0f / fConst0);
		float fConst5 = std::floor(((0.219990999f * fConst0) + 0.5f));
		fConst6 = ((0.0f - (6.90775537f * fConst5)) / fConst0);
		fConst7 = (3.14159274f / fConst0);
		float fConst8 = std::floor(((0.0191229992f * fConst0) + 0.5f));
		iConst9 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst5 - fConst8))));
		fConst10 = (0.00100000005f * fConst0);
		iConst11 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst8 + -1.0f))));
		float fConst12 = std::floor(((0.256891012f * fConst0) + 0.5f));
		fConst13 = ((0.0f - (6.90775537f * fConst12)) / fConst0);
		float fConst14 = std::floor(((0.0273330007f * fConst0) + 0.5f));
		iConst15 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst12 - fConst14))));
		iConst16 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst14 + -1.0f))));
		float fConst17 = std::floor(((0.192303002f * fConst0) + 0.5f));
		fConst18 = ((0.0f - (6.90775537f * fConst17)) / fConst0);
		float fConst19 = std::floor(((0.0292910002f * fConst0) + 0.5f));
		iConst20 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst17 - fConst19))));
		iConst21 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst19 + -1.0f))));
		float fConst22 = std::floor(((0.210389003f * fConst0) + 0.5f));
		fConst23 = ((0.0f - (6.90775537f * fConst22)) / fConst0);
		float fConst24 = std::floor(((0.0244210009f * fConst0) + 0.5f));
		iConst25 = int(std::min<float>(16384.0f, std::max<float>(0.0f, (fConst22 - fConst24))));
		iConst26 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst24 + -1.0f))));
		float fConst27 = std::floor(((0.127837002f * fConst0) + 0.5f));
		fConst28 = ((0.0f - (6.90775537f * fConst27)) / fConst0);
		float fConst29 = std::floor(((0.0316039994f * fConst0) + 0.5f));
		iConst30 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst27 - fConst29))));
		iConst31 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst29 + -1.0f))));
		float fConst32 = std::floor(((0.174713001f * fConst0) + 0.5f));
		fConst33 = ((0.0f - (6.90775537f * fConst32)) / fConst0);
		float fConst34 = std::floor(((0.0229039993f * fConst0) + 0.5f));
		iConst35 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst32 - fConst34))));
		iConst36 = int(std::min<float>(2048.0f, std::max<float>(0.0f, (fConst34 + -1.0f))));
		float fConst37 = std::floor(((0.153128996f * fConst0) + 0.5f));
		fConst38 = ((0.0f - (6.90775537f * fConst37)) / fConst0);
		float fConst39 = std::floor(((0.0203460008f * fConst0) + 0.5f));
		iConst40 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst37 - fConst39))));
		iConst41 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst39 + -1.0f))));
		float fConst42 = std::floor(((0.125f * fConst0) + 0.5f));
		fConst43 = ((0.0f - (6.90775537f * fConst42)) / fConst0);
		float fConst44 = std::floor(((0.0134579996f * fConst0) + 0.5f));
		iConst45 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst42 - fConst44))));
		iConst46 = int(std::min<float>(1024.0f, std::max<float>(0.0f, (fConst44 + -1.0f))));
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(-20.0f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(40.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(200.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fHslider6 = FAUSTFLOAT(1000.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(1.5f);
		fHslider9 = FAUSTFLOAT(100.0f);
		fHslider10 = FAUSTFLOAT(800.0f);
		fHslider11 = FAUSTFLOAT(0.5f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fHslider12 = FAUSTFLOAT(50.0f);
		fHslider13 = FAUSTFLOAT(5.0f);
		fHslider14 = FAUSTFLOAT(500.0f);
		fHslider15 = FAUSTFLOAT(-30.0f);
		fVslider2 = FAUSTFLOAT(315.0f);
		fVslider3 = FAUSTFLOAT(0.0f);
		fVslider4 = FAUSTFLOAT(2.0f);
		fVslider5 = FAUSTFLOAT(6000.0f);
		fVslider6 = FAUSTFLOAT(3.0f);
		fVslider7 = FAUSTFLOAT(200.0f);
		fVslider8 = FAUSTFLOAT(60.0f);
		fVslider9 = FAUSTFLOAT(1500.0f);
		fVslider10 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec8[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec9[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fVec1[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec10[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec5[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec4[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec3[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec2[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec16[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec15[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec13[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec12[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec11[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec25[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec24[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec23[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec21[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec20[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec19[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec18[l27] = 0.0f;
		}
		IOTA = 0;
		for (int l28 = 0; (l28 < 16384); l28 = (l28 + 1)) {
			fVec2[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec38[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec37[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 32768); l31 = (l31 + 1)) {
			fVec3[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec41[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec40[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec39[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 16384); l35 = (l35 + 1)) {
			fVec4[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2048); l36 = (l36 + 1)) {
			fVec5[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			fRec35[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec45[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec44[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 32768); l40 = (l40 + 1)) {
			fVec6[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 4096); l41 = (l41 + 1)) {
			fVec7[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec42[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec49[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec48[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 16384); l45 = (l45 + 1)) {
			fVec8[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 4096); l46 = (l46 + 1)) {
			fVec9[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec46[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fRec53[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec52[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 32768); l50 = (l50 + 1)) {
			fVec10[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 4096); l51 = (l51 + 1)) {
			fVec11[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) {
			fRec50[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fRec57[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec56[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 16384); l55 = (l55 + 1)) {
			fVec12[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 4096); l56 = (l56 + 1)) {
			fVec13[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fRec54[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec61[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			fRec60[l59] = 0.0f;
		}
		for (int l60 = 0; (l60 < 16384); l60 = (l60 + 1)) {
			fVec14[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 4096); l61 = (l61 + 1)) {
			fVec15[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec58[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			fRec65[l63] = 0.0f;
		}
		for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) {
			fRec64[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 16384); l65 = (l65 + 1)) {
			fVec16[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2048); l66 = (l66 + 1)) {
			fVec17[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			fRec62[l67] = 0.0f;
		}
		for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) {
			fRec69[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fRec68[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 16384); l70 = (l70 + 1)) {
			fVec18[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2048); l71 = (l71 + 1)) {
			fVec19[l71] = 0.0f;
		}
		for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) {
			fRec66[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 3); l73 = (l73 + 1)) {
			fRec27[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 3); l74 = (l74 + 1)) {
			fRec28[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 3); l75 = (l75 + 1)) {
			fRec29[l75] = 0.0f;
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec30[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 3); l77 = (l77 + 1)) {
			fRec31[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 3); l78 = (l78 + 1)) {
			fRec32[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 3); l79 = (l79 + 1)) {
			fRec33[l79] = 0.0f;
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec34[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 3); l81 = (l81 + 1)) {
			fRec26[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 3); l82 = (l82 + 1)) {
			fRec70[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 3); l83 = (l83 + 1)) {
			fRec71[l83] = 0.0f;
		}
		for (int l84 = 0; (l84 < 3); l84 = (l84 + 1)) {
			fRec72[l84] = 0.0f;
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
	
	virtual ChainDsp* clone() {
		return new ChainDsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("chain");
		ui_interface->declare(0, "tooltip", "Reference:         http://en.wikipedia.org/wiki/Dynamic_range_compression");
		ui_interface->openVerticalBox("COMPRESSOR");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fCheckbox0, "0", "");
		ui_interface->declare(&fCheckbox0, "tooltip", "When this is checked, the compressor         has no effect");
		ui_interface->addCheckButton("Bypass", &fCheckbox0);
		ui_interface->declare(&fHbargraph0, "1", "");
		ui_interface->declare(&fHbargraph0, "tooltip", "Current gain of     the compressor in dB");
		ui_interface->declare(&fHbargraph0, "unit", "dB");
		ui_interface->addHorizontalBargraph("Compressor Gain", &fHbargraph0, -50.0f, 10.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("Compression Control");
		ui_interface->declare(&fHslider13, "0", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->declare(&fHslider13, "tooltip", "A compression Ratio of N means that for each N dB increase in input     signal level above Threshold, the output level goes up 1 dB");
		ui_interface->addHorizontalSlider("Ratio", &fHslider13, 5.0f, 1.0f, 20.0f, 0.100000001f);
		ui_interface->declare(&fHslider15, "1", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->declare(&fHslider15, "tooltip", "When the signal level exceeds the Threshold (in dB), its level     is compressed according to the Ratio");
		ui_interface->declare(&fHslider15, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider15, -30.0f, -100.0f, 10.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("Compression Response");
		ui_interface->declare(&fHslider12, "1", "");
		ui_interface->declare(&fHslider12, "scale", "log");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->declare(&fHslider12, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain     to approach (exponentially) a new lower target level (the compression     `kicking in')");
		ui_interface->declare(&fHslider12, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider12, 50.0f, 1.0f, 1000.0f, 0.100000001f);
		ui_interface->declare(&fHslider14, "2", "");
		ui_interface->declare(&fHslider14, "scale", "log");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->declare(&fHslider14, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain     to approach (exponentially) a new higher target level (the compression     'releasing')");
		ui_interface->declare(&fHslider14, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider14, 500.0f, 1.0f, 1000.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(&fHslider0, "5", "");
		ui_interface->declare(&fHslider0, "tooltip", "The compressed-signal output level is increased by this amount     (in dB) to make up for the level lost due to compression");
		ui_interface->declare(&fHslider0, "unit", "dB");
		ui_interface->addHorizontalSlider("Makeup Gain", &fHslider0, 40.0f, -96.0f, 96.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "tooltip", "Reference:         https://ccrma.stanford.edu/~jos/pasp/Cubic_Soft_Clipper.html");
		ui_interface->openVerticalBox("CUBIC NONLINEARITY cubicnl");
		ui_interface->declare(&fCheckbox3, "0", "");
		ui_interface->declare(&fCheckbox3, "tooltip", "When this is checked, the         nonlinearity has no effect");
		ui_interface->addCheckButton("Bypass", &fCheckbox3);
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "tooltip", "Amount of distortion");
		ui_interface->addHorizontalSlider("Drive", &fHslider3, 0.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "tooltip", "Brings in even harmonics");
		ui_interface->addHorizontalSlider("Offset", &fHslider2, 0.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->closeBox();
		ui_interface->declare(0, "tooltip", "Reference:         https://ccrma.stanford.edu/~jos/pasp/Flanging.html");
		ui_interface->openVerticalBox("PHASER2");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fCheckbox1, "0", "");
		ui_interface->declare(&fCheckbox1, "tooltip", "When this is checked, the phaser         has no effect");
		ui_interface->addCheckButton("Bypass", &fCheckbox1);
		ui_interface->declare(&fCheckbox5, "1", "");
		ui_interface->addCheckButton("Invert Internal Phaser Sum", &fCheckbox5);
		ui_interface->declare(&fCheckbox4, "2", "");
		ui_interface->addCheckButton("Vibrato Mode", &fCheckbox4);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fHslider11, "1", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->declare(&fHslider11, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider11, 0.5f, 0.0f, 10.0f, 0.00100000005f);
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("Notch Depth (Intensity)", &fHslider5, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider7, "3", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("Feedback Gain", &fHslider7, 0.0f, -0.999000013f, 0.999000013f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "scale", "log");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->declare(&fHslider6, "unit", "Hz");
		ui_interface->addHorizontalSlider("Notch width", &fHslider6, 1000.0f, 10.0f, 5000.0f, 1.0f);
		ui_interface->declare(&fHslider9, "2", "");
		ui_interface->declare(&fHslider9, "scale", "log");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->declare(&fHslider9, "unit", "Hz");
		ui_interface->addHorizontalSlider("Min Notch1 Freq", &fHslider9, 100.0f, 20.0f, 5000.0f, 1.0f);
		ui_interface->declare(&fHslider10, "3", "");
		ui_interface->declare(&fHslider10, "scale", "log");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->declare(&fHslider10, "unit", "Hz");
		ui_interface->addHorizontalSlider("Max Notch1 Freq", &fHslider10, 800.0f, 20.0f, 10000.0f, 1.0f);
		ui_interface->declare(&fHslider8, "4", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("Notch Freq Ratio: NotchFreq(n+1)/NotchFreq(n)", &fHslider8, 1.5f, 1.10000002f, 4.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Phaser Output Level", &fHslider1, 0.0f, -60.0f, 10.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "tooltip", "Fourth-order wah effect made using moog_vcf");
		ui_interface->openHorizontalBox("WAH4");
		ui_interface->declare(&fCheckbox2, "0", "");
		ui_interface->declare(&fCheckbox2, "tooltip", "When this is checked, the wah pedal has         no effect");
		ui_interface->addCheckButton("Bypass", &fCheckbox2);
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "scale", "log");
		ui_interface->declare(&fHslider4, "tooltip", "wah resonance         frequency in Hz");
		ui_interface->addHorizontalSlider("Resonance Frequency", &fHslider4, 200.0f, 100.0f, 2000.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER     ALLPASS-COMB REVERBERATOR (8x8). See Faust's reverbs.lib for documentation and     references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fVslider8, "1", "");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "Delay in ms         before reverberation begins");
		ui_interface->declare(&fVslider8, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fVslider8, 60.0f, 20.0f, 100.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fVslider7, "1", "");
		ui_interface->declare(&fVslider7, "scale", "log");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider7, "unit", "Hz");
		ui_interface->addVerticalSlider("LF X", &fVslider7, 200.0f, 50.0f, 1000.0f, 1.0f);
		ui_interface->declare(&fVslider6, "2", "");
		ui_interface->declare(&fVslider6, "scale", "log");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fVslider6, "unit", "s");
		ui_interface->addVerticalSlider("Low RT60", &fVslider6, 3.0f, 1.0f, 8.0f, 0.100000001f);
		ui_interface->declare(&fVslider4, "3", "");
		ui_interface->declare(&fVslider4, "scale", "log");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider4, "unit", "s");
		ui_interface->addVerticalSlider("Mid RT60", &fVslider4, 2.0f, 1.0f, 8.0f, 0.100000001f);
		ui_interface->declare(&fVslider5, "4", "");
		ui_interface->declare(&fVslider5, "scale", "log");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fVslider5, 6000.0f, 1500.0f, 23520.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 1");
		ui_interface->declare(&fVslider2, "1", "");
		ui_interface->declare(&fVslider2, "scale", "log");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider2, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq1 Freq", &fVslider2, 315.0f, 40.0f, 2500.0f, 1.0f);
		ui_interface->declare(&fVslider3, "2", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider3, "unit", "dB");
		ui_interface->addVerticalSlider("Eq1 Level", &fVslider3, 0.0f, -15.0f, 15.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 2");
		ui_interface->declare(&fVslider9, "1", "");
		ui_interface->declare(&fVslider9, "scale", "log");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider9, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq2 Freq", &fVslider9, 1500.0f, 160.0f, 10000.0f, 1.0f);
		ui_interface->declare(&fVslider10, "2", "");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "Peak level         in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider10, "unit", "dB");
		ui_interface->addVerticalSlider("Eq2 Level", &fVslider10, 0.0f, -15.0f, 15.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("Dry/Wet Mix", &fVslider1, 0.0f, -1.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fVslider0, "2", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "Output scale         factor");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("Level", &fVslider0, -20.0f, -70.0f, 40.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (fConst1 * std::pow(10.0f, (0.0500000007f * float(fVslider0))));
		float fSlow1 = (fConst1 * float(fVslider1));
		int iSlow2 = int(float(fCheckbox0));
		float fSlow3 = std::pow(10.0f, (0.0500000007f * float(fHslider0)));
		int iSlow4 = int(float(fCheckbox1));
		float fSlow5 = std::pow(10.0f, (0.0500000007f * float(fHslider1)));
		int iSlow6 = int(float(fCheckbox2));
		int iSlow7 = int(float(fCheckbox3));
		float fSlow8 = (fConst1 * float(fHslider2));
		float fSlow9 = (fConst1 * float(fHslider3));
		float fSlow10 = (0.00100000005f * float(fHslider4));
		float fSlow11 = (0.5f * (int(float(fCheckbox4)) ? 2.0f : float(fHslider5)));
		float fSlow12 = (1.0f - fSlow11);
		float fSlow13 = std::exp((fConst4 * (0.0f - (3.14159274f * float(fHslider6)))));
		float fSlow14 = (0.0f - (2.0f * fSlow13));
		float fSlow15 = ChainDsp_faustpower2_f(fSlow13);
		float fSlow16 = float(fHslider7);
		float fSlow17 = float(fHslider8);
		float fSlow18 = float(fHslider9);
		float fSlow19 = (fConst3 * fSlow18);
		float fSlow20 = (0.5f * (0.0f - (fConst3 * (fSlow18 - std::max<float>(fSlow18, float(fHslider10))))));
		float fSlow21 = (fConst3 * float(fHslider11));
		float fSlow22 = std::sin(fSlow21);
		float fSlow23 = std::cos(fSlow21);
		float fSlow24 = ChainDsp_faustpower2_f(fSlow17);
		float fSlow25 = ChainDsp_faustpower3_f(fSlow17);
		float fSlow26 = ChainDsp_faustpower4_f(fSlow17);
		float fSlow27 = (int(float(fCheckbox5)) ? (-1.0f * fSlow11) : fSlow11);
		float fSlow28 = std::max<float>(fConst4, (0.00100000005f * float(fHslider12)));
		float fSlow29 = (0.5f * fSlow28);
		int iSlow30 = (std::fabs(fSlow29) < 1.1920929e-07f);
		float fSlow31 = (iSlow30 ? 0.0f : std::exp((0.0f - (fConst4 / (iSlow30 ? 1.0f : fSlow29)))));
		float fSlow32 = ((1.0f / std::max<float>(1.1920929e-07f, float(fHslider13))) + -1.0f);
		int iSlow33 = (std::fabs(fSlow28) < 1.1920929e-07f);
		float fSlow34 = (iSlow33 ? 0.0f : std::exp((0.0f - (fConst4 / (iSlow33 ? 1.0f : fSlow28)))));
		float fSlow35 = std::max<float>(fConst4, (0.00100000005f * float(fHslider14)));
		int iSlow36 = (std::fabs(fSlow35) < 1.1920929e-07f);
		float fSlow37 = (iSlow36 ? 0.0f : std::exp((0.0f - (fConst4 / (iSlow36 ? 1.0f : fSlow35)))));
		float fSlow38 = float(fHslider15);
		float fSlow39 = (1.0f - fSlow31);
		float fSlow40 = float(fVslider2);
		float fSlow41 = std::pow(10.0f, (0.0500000007f * float(fVslider3)));
		float fSlow42 = (fConst3 * (fSlow40 / std::sqrt(std::max<float>(0.0f, fSlow41))));
		float fSlow43 = ((1.0f - fSlow42) / (fSlow42 + 1.0f));
		float fSlow44 = float(fVslider4);
		float fSlow45 = std::exp((fConst6 / fSlow44));
		float fSlow46 = ChainDsp_faustpower2_f(fSlow45);
		float fSlow47 = std::cos((fConst3 * float(fVslider5)));
		float fSlow48 = (1.0f - (fSlow46 * fSlow47));
		float fSlow49 = (1.0f - fSlow46);
		float fSlow50 = (fSlow48 / fSlow49);
		float fSlow51 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow48) / ChainDsp_faustpower2_f(fSlow49)) + -1.0f)));
		float fSlow52 = (fSlow50 - fSlow51);
		float fSlow53 = (fSlow45 * (fSlow51 + (1.0f - fSlow50)));
		float fSlow54 = float(fVslider6);
		float fSlow55 = ((std::exp((fConst6 / fSlow54)) / fSlow45) + -1.0f);
		float fSlow56 = (1.0f / std::tan((fConst7 * float(fVslider7))));
		float fSlow57 = (1.0f / (fSlow56 + 1.0f));
		float fSlow58 = (1.0f - fSlow56);
		int iSlow59 = int(std::min<float>(8192.0f, std::max<float>(0.0f, (fConst10 * float(fVslider8)))));
		float fSlow60 = std::exp((fConst13 / fSlow44));
		float fSlow61 = ChainDsp_faustpower2_f(fSlow60);
		float fSlow62 = (1.0f - (fSlow61 * fSlow47));
		float fSlow63 = (1.0f - fSlow61);
		float fSlow64 = (fSlow62 / fSlow63);
		float fSlow65 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow62) / ChainDsp_faustpower2_f(fSlow63)) + -1.0f)));
		float fSlow66 = (fSlow64 - fSlow65);
		float fSlow67 = (fSlow60 * (fSlow65 + (1.0f - fSlow64)));
		float fSlow68 = ((std::exp((fConst13 / fSlow54)) / fSlow60) + -1.0f);
		float fSlow69 = std::exp((fConst18 / fSlow44));
		float fSlow70 = ChainDsp_faustpower2_f(fSlow69);
		float fSlow71 = (1.0f - (fSlow70 * fSlow47));
		float fSlow72 = (1.0f - fSlow70);
		float fSlow73 = (fSlow71 / fSlow72);
		float fSlow74 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow71) / ChainDsp_faustpower2_f(fSlow72)) + -1.0f)));
		float fSlow75 = (fSlow73 - fSlow74);
		float fSlow76 = (fSlow69 * (fSlow74 + (1.0f - fSlow73)));
		float fSlow77 = ((std::exp((fConst18 / fSlow54)) / fSlow69) + -1.0f);
		float fSlow78 = std::exp((fConst23 / fSlow44));
		float fSlow79 = ChainDsp_faustpower2_f(fSlow78);
		float fSlow80 = (1.0f - (fSlow79 * fSlow47));
		float fSlow81 = (1.0f - fSlow79);
		float fSlow82 = (fSlow80 / fSlow81);
		float fSlow83 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow80) / ChainDsp_faustpower2_f(fSlow81)) + -1.0f)));
		float fSlow84 = (fSlow82 - fSlow83);
		float fSlow85 = (fSlow78 * (fSlow83 + (1.0f - fSlow82)));
		float fSlow86 = ((std::exp((fConst23 / fSlow54)) / fSlow78) + -1.0f);
		float fSlow87 = std::exp((fConst28 / fSlow44));
		float fSlow88 = ChainDsp_faustpower2_f(fSlow87);
		float fSlow89 = (1.0f - (fSlow88 * fSlow47));
		float fSlow90 = (1.0f - fSlow88);
		float fSlow91 = (fSlow89 / fSlow90);
		float fSlow92 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow89) / ChainDsp_faustpower2_f(fSlow90)) + -1.0f)));
		float fSlow93 = (fSlow91 - fSlow92);
		float fSlow94 = (fSlow87 * (fSlow92 + (1.0f - fSlow91)));
		float fSlow95 = ((std::exp((fConst28 / fSlow54)) / fSlow87) + -1.0f);
		float fSlow96 = std::exp((fConst33 / fSlow44));
		float fSlow97 = ChainDsp_faustpower2_f(fSlow96);
		float fSlow98 = (1.0f - (fSlow97 * fSlow47));
		float fSlow99 = (1.0f - fSlow97);
		float fSlow100 = (fSlow98 / fSlow99);
		float fSlow101 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow98) / ChainDsp_faustpower2_f(fSlow99)) + -1.0f)));
		float fSlow102 = (fSlow100 - fSlow101);
		float fSlow103 = (fSlow96 * (fSlow101 + (1.0f - fSlow100)));
		float fSlow104 = ((std::exp((fConst33 / fSlow54)) / fSlow96) + -1.0f);
		float fSlow105 = std::exp((fConst38 / fSlow44));
		float fSlow106 = ChainDsp_faustpower2_f(fSlow105);
		float fSlow107 = (1.0f - (fSlow106 * fSlow47));
		float fSlow108 = (1.0f - fSlow106);
		float fSlow109 = (fSlow107 / fSlow108);
		float fSlow110 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow107) / ChainDsp_faustpower2_f(fSlow108)) + -1.0f)));
		float fSlow111 = (fSlow109 - fSlow110);
		float fSlow112 = (fSlow105 * (fSlow110 + (1.0f - fSlow109)));
		float fSlow113 = ((std::exp((fConst38 / fSlow54)) / fSlow105) + -1.0f);
		float fSlow114 = std::exp((fConst43 / fSlow44));
		float fSlow115 = ChainDsp_faustpower2_f(fSlow114);
		float fSlow116 = (1.0f - (fSlow115 * fSlow47));
		float fSlow117 = (1.0f - fSlow115);
		float fSlow118 = (fSlow116 / fSlow117);
		float fSlow119 = std::sqrt(std::max<float>(0.0f, ((ChainDsp_faustpower2_f(fSlow116) / ChainDsp_faustpower2_f(fSlow117)) + -1.0f)));
		float fSlow120 = (fSlow118 - fSlow119);
		float fSlow121 = (fSlow114 * (fSlow119 + (1.0f - fSlow118)));
		float fSlow122 = ((std::exp((fConst43 / fSlow54)) / fSlow114) + -1.0f);
		float fSlow123 = (0.0f - (std::cos((fConst3 * fSlow40)) * (fSlow43 + 1.0f)));
		float fSlow124 = float(fVslider9);
		float fSlow125 = std::pow(10.0f, (0.0500000007f * float(fVslider10)));
		float fSlow126 = (fConst3 * (fSlow124 / std::sqrt(std::max<float>(0.0f, fSlow125))));
		float fSlow127 = ((1.0f - fSlow126) / (fSlow126 + 1.0f));
		float fSlow128 = (0.0f - (std::cos((fConst3 * fSlow124)) * (fSlow127 + 1.0f)));
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			iVec0[0] = 1;
			fRec0[0] = (fSlow0 + (fConst2 * fRec0[1]));
			fRec1[0] = (fSlow1 + (fConst2 * fRec1[1]));
			float fTemp0 = (fRec1[0] + 1.0f);
			fRec8[0] = (fSlow8 + (fConst2 * fRec8[1]));
			fRec9[0] = (fSlow9 + (fConst2 * fRec9[1]));
			float fTemp1 = float(input0[i0]);
			float fTemp2 = std::max<float>(-1.0f, std::min<float>(1.0f, (fRec8[0] + (std::pow(10.0f, (2.0f * fRec9[0])) * (iSlow7 ? 0.0f : fTemp1)))));
			float fTemp3 = (fTemp2 * (1.0f - (0.333333343f * ChainDsp_faustpower2_f(fTemp2))));
			fVec1[0] = fTemp3;
			fRec7[0] = (((0.995000005f * fRec7[1]) + fTemp3) - fVec1[1]);
			float fTemp4 = (iSlow7 ? fTemp1 : fRec7[0]);
			fRec10[0] = (fSlow10 + (0.999000013f * fRec10[1]));
			float fTemp5 = (fConst3 * fRec10[0]);
			float fTemp6 = (1.0f - fTemp5);
			fRec6[0] = (((iSlow6 ? 0.0f : fTemp4) + (fTemp6 * fRec6[1])) - (3.20000005f * fRec2[1]));
			fRec5[0] = (fRec6[0] + (fTemp6 * fRec5[1]));
			fRec4[0] = (fRec5[0] + (fTemp6 * fRec4[1]));
			fRec3[0] = (fRec4[0] + (fRec3[1] * fTemp6));
			fRec2[0] = (fRec3[0] * std::pow(fTemp5, 4.0f));
			float fTemp7 = (iSlow6 ? fTemp4 : (4.0f * fRec2[0]));
			float fTemp8 = (iSlow4 ? 0.0f : fTemp7);
			float fTemp9 = (fSlow5 * (fTemp8 * fSlow12));
			float fTemp10 = (fSlow5 * fTemp8);
			fRec16[0] = ((fSlow22 * fRec17[1]) + (fSlow23 * fRec16[1]));
			fRec17[0] = ((float((1 - iVec0[1])) + (fSlow23 * fRec17[1])) - (fSlow22 * fRec16[1]));
			float fTemp11 = (fSlow19 + (fSlow20 * (1.0f - fRec16[0])));
			float fTemp12 = (fRec15[1] * std::cos((fSlow17 * fTemp11)));
			fRec15[0] = ((fTemp10 + (fSlow16 * fRec11[1])) - ((fSlow14 * fTemp12) + (fSlow15 * fRec15[2])));
			float fTemp13 = (fRec14[1] * std::cos((fSlow24 * fTemp11)));
			fRec14[0] = ((fSlow15 * (fRec15[0] - fRec14[2])) + (fRec15[2] + (fSlow14 * (fTemp12 - fTemp13))));
			float fTemp14 = (fRec13[1] * std::cos((fSlow25 * fTemp11)));
			fRec13[0] = ((fSlow14 * (fTemp13 - fTemp14)) + (fRec14[2] + (fSlow15 * (fRec14[0] - fRec13[2]))));
			float fTemp15 = (fRec12[1] * std::cos((fSlow26 * fTemp11)));
			fRec12[0] = ((fRec13[2] + (fSlow14 * (fTemp14 - fTemp15))) - (fSlow15 * (fRec12[2] - fRec13[0])));
			fRec11[0] = ((fSlow14 * fTemp15) + (fRec12[2] + (fSlow15 * fRec12[0])));
			float fTemp16 = (iSlow4 ? fTemp7 : (fTemp9 + (fRec11[0] * fSlow27)));
			float fTemp17 = (iSlow2 ? 0.0f : fTemp16);
			float fTemp18 = (fSlow19 + (fSlow20 * (1.0f - fRec17[0])));
			float fTemp19 = (fRec25[1] * std::cos((fSlow17 * fTemp18)));
			fRec25[0] = ((fTemp10 + (fSlow16 * fRec21[1])) - ((fSlow14 * fTemp19) + (fSlow15 * fRec25[2])));
			float fTemp20 = (fRec24[1] * std::cos((fSlow24 * fTemp18)));
			fRec24[0] = ((fSlow14 * (fTemp19 - fTemp20)) + (fRec25[2] + (fSlow15 * (fRec25[0] - fRec24[2]))));
			float fTemp21 = (fRec23[1] * std::cos((fSlow25 * fTemp18)));
			fRec23[0] = ((fSlow15 * (fRec24[0] - fRec23[2])) + (fRec24[2] + (fSlow14 * (fTemp20 - fTemp21))));
			float fTemp22 = (fRec22[1] * std::cos((fSlow26 * fTemp18)));
			fRec22[0] = ((fRec23[2] + (fSlow15 * (fRec23[0] - fRec22[2]))) - (fSlow14 * (fTemp22 - fTemp21)));
			fRec21[0] = ((fSlow14 * fTemp22) + (fRec22[2] + (fSlow15 * fRec22[0])));
			float fTemp23 = (iSlow4 ? fTemp7 : (fTemp9 + (fRec21[0] * fSlow27)));
			float fTemp24 = (iSlow2 ? 0.0f : fTemp23);
			float fTemp25 = std::fabs((std::fabs(fTemp17) + std::fabs(fTemp24)));
			float fTemp26 = ((fRec19[1] > fTemp25) ? fSlow37 : fSlow34);
			fRec20[0] = ((fRec20[1] * fTemp26) + (fTemp25 * (1.0f - fTemp26)));
			fRec19[0] = fRec20[0];
			fRec18[0] = ((fRec18[1] * fSlow31) + (fSlow32 * (std::max<float>(((20.0f * std::log10(fRec19[0])) - fSlow38), 0.0f) * fSlow39)));
			float fTemp27 = std::pow(10.0f, (0.0500000007f * fRec18[0]));
			float fTemp28 = (fTemp17 * fTemp27);
			float fTemp29 = (iSlow2 ? fTemp16 : (fSlow3 * fTemp28));
			fVec2[(IOTA & 16383)] = fTemp29;
			float fTemp30 = (1.0f - (0.5f * fTemp0));
			fRec38[0] = (0.0f - (fSlow57 * ((fSlow58 * fRec38[1]) - (fRec34[1] + fRec34[2]))));
			fRec37[0] = ((fSlow52 * fRec37[1]) + (fSlow53 * (fRec34[1] + (fSlow55 * fRec38[0]))));
			fVec3[(IOTA & 32767)] = ((0.353553385f * fRec37[0]) + 9.99999968e-21f);
			float fTemp31 = (fTemp24 * fTemp27);
			float fTemp32 = std::fabs((std::fabs(fTemp28) + std::fabs(fTemp31)));
			float fTemp33 = ((fRec40[1] > fTemp32) ? fSlow37 : fSlow34);
			fRec41[0] = ((fRec41[1] * fTemp33) + (fTemp32 * (1.0f - fTemp33)));
			fRec40[0] = fRec41[0];
			fRec39[0] = ((fSlow31 * fRec39[1]) + (fSlow32 * (std::max<float>(((20.0f * std::log10(fRec40[0])) - fSlow38), 0.0f) * fSlow39)));
			fHbargraph0 = FAUSTFLOAT((20.0f * std::log10(std::pow(10.0f, (0.0500000007f * fRec39[0])))));
			float fTemp34 = (iSlow2 ? fTemp23 : (fSlow3 * fTemp31));
			fVec4[(IOTA & 16383)] = fTemp34;
			float fTemp35 = (0.300000012f * fVec4[((IOTA - iSlow59) & 16383)]);
			float fTemp36 = (((0.600000024f * fRec35[1]) + fVec3[((IOTA - iConst9) & 32767)]) - fTemp35);
			fVec5[(IOTA & 2047)] = fTemp36;
			fRec35[0] = fVec5[((IOTA - iConst11) & 2047)];
			float fRec36 = (0.0f - (0.600000024f * fTemp36));
			fRec45[0] = (fSlow57 * ((fRec30[1] + fRec30[2]) - (fSlow58 * fRec45[1])));
			fRec44[0] = ((fSlow66 * fRec44[1]) + (fSlow67 * (fRec30[1] + (fSlow68 * fRec45[0]))));
			fVec6[(IOTA & 32767)] = ((0.353553385f * fRec44[0]) + 9.99999968e-21f);
			float fTemp37 = (((0.600000024f * fRec42[1]) + fVec6[((IOTA - iConst15) & 32767)]) - fTemp35);
			fVec7[(IOTA & 4095)] = fTemp37;
			fRec42[0] = fVec7[((IOTA - iConst16) & 4095)];
			float fRec43 = (0.0f - (0.600000024f * fTemp37));
			fRec49[0] = (0.0f - (fSlow57 * ((fSlow58 * fRec49[1]) - (fRec32[1] + fRec32[2]))));
			fRec48[0] = ((fSlow75 * fRec48[1]) + (fSlow76 * (fRec32[1] + (fSlow77 * fRec49[0]))));
			fVec8[(IOTA & 16383)] = ((0.353553385f * fRec48[0]) + 9.99999968e-21f);
			float fTemp38 = (fVec8[((IOTA - iConst20) & 16383)] + (fTemp35 + (0.600000024f * fRec46[1])));
			fVec9[(IOTA & 4095)] = fTemp38;
			fRec46[0] = fVec9[((IOTA - iConst21) & 4095)];
			float fRec47 = (0.0f - (0.600000024f * fTemp38));
			fRec53[0] = (0.0f - (fSlow57 * ((fSlow58 * fRec53[1]) - (fRec28[1] + fRec28[2]))));
			fRec52[0] = ((fSlow84 * fRec52[1]) + (fSlow85 * (fRec28[1] + (fSlow86 * fRec53[0]))));
			fVec10[(IOTA & 32767)] = ((0.353553385f * fRec52[0]) + 9.99999968e-21f);
			float fTemp39 = (fTemp35 + ((0.600000024f * fRec50[1]) + fVec10[((IOTA - iConst25) & 32767)]));
			fVec11[(IOTA & 4095)] = fTemp39;
			fRec50[0] = fVec11[((IOTA - iConst26) & 4095)];
			float fRec51 = (0.0f - (0.600000024f * fTemp39));
			fRec57[0] = (fSlow57 * ((fRec29[1] + fRec29[2]) - (fSlow58 * fRec57[1])));
			fRec56[0] = ((fSlow93 * fRec56[1]) + (fSlow94 * (fRec29[1] + (fSlow95 * fRec57[0]))));
			fVec12[(IOTA & 16383)] = ((0.353553385f * fRec56[0]) + 9.99999968e-21f);
			float fTemp40 = (0.300000012f * fVec2[((IOTA - iSlow59) & 16383)]);
			float fTemp41 = (fVec12[((IOTA - iConst30) & 16383)] - (fTemp40 + (0.600000024f * fRec54[1])));
			fVec13[(IOTA & 4095)] = fTemp41;
			fRec54[0] = fVec13[((IOTA - iConst31) & 4095)];
			float fRec55 = (0.600000024f * fTemp41);
			fRec61[0] = (0.0f - (fSlow57 * ((fSlow58 * fRec61[1]) - (fRec31[1] + fRec31[2]))));
			fRec60[0] = ((fSlow102 * fRec60[1]) + (fSlow103 * (fRec31[1] + (fSlow104 * fRec61[0]))));
			fVec14[(IOTA & 16383)] = ((0.353553385f * fRec60[0]) + 9.99999968e-21f);
			float fTemp42 = ((fTemp40 + fVec14[((IOTA - iConst35) & 16383)]) - (0.600000024f * fRec58[1]));
			fVec15[(IOTA & 4095)] = fTemp42;
			fRec58[0] = fVec15[((IOTA - iConst36) & 4095)];
			float fRec59 = (0.600000024f * fTemp42);
			fRec65[0] = (fSlow57 * ((fRec27[1] + fRec27[2]) - (fSlow58 * fRec65[1])));
			fRec64[0] = ((fSlow111 * fRec64[1]) + (fSlow112 * (fRec27[1] + (fSlow113 * fRec65[0]))));
			fVec16[(IOTA & 16383)] = ((0.353553385f * fRec64[0]) + 9.99999968e-21f);
			float fTemp43 = ((fVec16[((IOTA - iConst40) & 16383)] + fTemp40) - (0.600000024f * fRec62[1]));
			fVec17[(IOTA & 2047)] = fTemp43;
			fRec62[0] = fVec17[((IOTA - iConst41) & 2047)];
			float fRec63 = (0.600000024f * fTemp43);
			fRec69[0] = (fSlow57 * ((fRec33[1] + fRec33[2]) - (fSlow58 * fRec69[1])));
			fRec68[0] = ((fSlow120 * fRec68[1]) + (fSlow121 * (fRec33[1] + (fSlow122 * fRec69[0]))));
			fVec18[(IOTA & 16383)] = ((0.353553385f * fRec68[0]) + 9.99999968e-21f);
			float fTemp44 = (fVec18[((IOTA - iConst45) & 16383)] - (fTemp40 + (0.600000024f * fRec66[1])));
			fVec19[(IOTA & 2047)] = fTemp44;
			fRec66[0] = fVec19[((IOTA - iConst46) & 2047)];
			float fRec67 = (0.600000024f * fTemp44);
			float fTemp45 = (fRec63 + fRec59);
			float fTemp46 = (fRec67 + (fRec55 + fTemp45));
			fRec27[0] = (fRec35[1] + (fRec42[1] + (fRec46[1] + (fRec50[1] + (fRec54[1] + (fRec58[1] + (fRec62[1] + (fRec66[1] + (fRec36 + (fRec43 + (fRec47 + (fRec51 + fTemp46))))))))))));
			fRec28[0] = ((fRec54[1] + (fRec58[1] + (fRec62[1] + (fRec66[1] + fTemp46)))) - (fRec35[1] + (fRec42[1] + (fRec46[1] + (fRec50[1] + (fRec36 + (fRec43 + (fRec51 + fRec47))))))));
			float fTemp47 = (fRec55 + fRec67);
			fRec29[0] = ((fRec46[1] + (fRec50[1] + (fRec58[1] + (fRec62[1] + (fRec47 + (fRec51 + fTemp45)))))) - (fRec35[1] + (fRec42[1] + (fRec54[1] + (fRec66[1] + (fRec36 + (fRec43 + fTemp47)))))));
			fRec30[0] = ((fRec35[1] + (fRec42[1] + (fRec58[1] + (fRec62[1] + (fRec36 + (fRec43 + fTemp45)))))) - (fRec46[1] + (fRec50[1] + (fRec54[1] + (fRec66[1] + (fRec47 + (fRec51 + fTemp47)))))));
			float fTemp48 = (fRec63 + fRec55);
			float fTemp49 = (fRec59 + fRec67);
			fRec31[0] = ((fRec42[1] + (fRec50[1] + (fRec54[1] + (fRec62[1] + (fRec43 + (fRec51 + fTemp48)))))) - (fRec35[1] + (fRec46[1] + (fRec58[1] + (fRec66[1] + (fRec36 + (fRec47 + fTemp49)))))));
			fRec32[0] = ((fRec35[1] + (fRec46[1] + (fRec54[1] + (fRec62[1] + (fRec36 + (fRec47 + fTemp48)))))) - (fRec42[1] + (fRec50[1] + (fRec58[1] + (fRec66[1] + (fRec43 + (fRec51 + fTemp49)))))));
			float fTemp50 = (fRec63 + fRec67);
			float fTemp51 = (fRec59 + fRec55);
			fRec33[0] = ((fRec35[1] + (fRec50[1] + (fRec62[1] + (fRec66[1] + (fRec36 + (fRec51 + fTemp50)))))) - (fRec42[1] + (fRec46[1] + (fRec54[1] + (fRec58[1] + (fRec43 + (fRec47 + fTemp51)))))));
			fRec34[0] = ((fRec42[1] + (fRec46[1] + (fRec62[1] + (fRec66[1] + (fRec43 + (fRec47 + fTemp50)))))) - (fRec35[1] + (fRec50[1] + (fRec54[1] + (fRec58[1] + (fRec36 + (fRec51 + fTemp51)))))));
			float fTemp52 = (0.370000005f * (fRec28[0] + fRec29[0]));
			float fTemp53 = (fSlow123 * fRec26[1]);
			fRec26[0] = (fTemp52 - (fTemp53 + (fSlow43 * fRec26[2])));
			float fTemp54 = (fSlow43 * fRec26[0]);
			float fTemp55 = (0.5f * ((fTemp54 + (fRec26[2] + (fTemp52 + fTemp53))) + (fSlow41 * ((fTemp54 + (fTemp53 + fRec26[2])) - fTemp52))));
			float fTemp56 = (fSlow128 * fRec70[1]);
			fRec70[0] = (fTemp55 - (fTemp56 + (fSlow127 * fRec70[2])));
			float fTemp57 = ((fSlow127 * fRec70[0]) + (fTemp56 + fRec70[2]));
			output0[i0] = FAUSTFLOAT((0.5f * (fRec0[0] * ((fTemp0 * fTemp29) + (fTemp30 * ((fTemp55 + fTemp57) + (fSlow125 * (fTemp57 - fTemp55))))))));
			float fTemp58 = (0.370000005f * (fRec28[0] - fRec29[0]));
			float fTemp59 = (fSlow123 * fRec71[1]);
			fRec71[0] = (fTemp58 - (fTemp59 + (fSlow43 * fRec71[2])));
			float fTemp60 = (fSlow43 * fRec71[0]);
			float fTemp61 = (0.5f * ((fTemp60 + (fRec71[2] + (fTemp58 + fTemp59))) + (fSlow41 * ((fTemp60 + (fTemp59 + fRec71[2])) - fTemp58))));
			float fTemp62 = (fSlow128 * fRec72[1]);
			fRec72[0] = (fTemp61 - (fTemp62 + (fSlow127 * fRec72[2])));
			float fTemp63 = (fRec72[2] + (fTemp62 + (fSlow127 * fRec72[0])));
			output1[i0] = FAUSTFLOAT((0.5f * (fRec0[0] * ((fTemp0 * fTemp34) + (fTemp30 * ((fTemp61 + fTemp63) + (fSlow125 * (fTemp63 - fTemp61))))))));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fVec1[1] = fVec1[0];
			fRec7[1] = fRec7[0];
			fRec10[1] = fRec10[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			IOTA = (IOTA + 1);
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec35[1] = fRec35[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec42[1] = fRec42[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec54[1] = fRec54[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
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
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec70[2] = fRec70[1];
			fRec70[1] = fRec70[0];
			fRec71[2] = fRec71[1];
			fRec71[1] = fRec71[0];
			fRec72[2] = fRec72[1];
			fRec72[1] = fRec72[0];
		}
	}

};

#endif
