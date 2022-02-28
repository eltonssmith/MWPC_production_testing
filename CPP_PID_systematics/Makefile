#
# Makefile to latex document, uncompress .ps files etc...
# original version : Mark Ito
# modified:
#
#     use for hadron05 paper - Elton Smith 9/30/03
#     html output de-activated for now
#     halld_safety - Elton Smith 10/16/06
#     cc_geometry - Elton Smith 10/16/06
#     bcal_specs - Elton Smith 04/02/07
#     halld_specs - Elton Smith 08/27/07
#     feldman_cousins - Elton Smith 09/17/07
#     feldman_cousins systematics  - Elton Smith 08/05/08
#     cdc_segments  - Elton Smith 09/31/08
#     sipm_cooling  - Elton Smith 09/31/08
#     b1pi_studies  - Elton Smith 02/24/10
#     b1_pi studies  - Elton Smith 03/18/10
#     gen_eta studies  - Elton Smith 04/26/10
#     short_currents - Elton Smith 06/22/10
#     short_response - Elton Smith 09/24/10
#     short_cover - Elton Smith 09/24/10   -- use pdflatex
#     solenoid_replacement - Elton Smith 10/15/10   -- use pdflatex
#     bcal_prod_guides  - Elton Smith 06/08/11   -- use pdflatex
#     bcal_voltage_settings  - Elton Smith 26/09/14  -- use pdflatex
#     photon_rates  - Elton Smith 10/21/14  -- use pdflatex
#     double_slit  - Elton Smith 11/12/14  -- use pdflatex
#     bcal_constants  - Elton Smith 12/02/14  -- use pdflatex
#     SiPM_saturation  - Elton Smith 7/13/18  -- use pdflatex
#     CalEff  - Elton Smith 12/21/18  -- use pdflatex
#     CostheEff  - Elton Smith 04/19/19  -- use pdflatex
#     MWPC_production_testing  - Elton Smith 04/19/19  -- use pdflatex#
#     CPP_PID_systematics  - Elton Smith 02/16/2022  -- use pdflatex#
#
TEX_FILES_0 = CPP_PID_systematics
TEX_FILES = $(addsuffix .tex,$(TEX_FILES_0)) # add .tex suffix

PNG_FILES_0 = Proposal_Table2 toy_systematics_c1 cpp_systematics_lpi025_lmu005_c2 cpp_systematics_lpi025_lmu005_c3 \
              cpp_systematics_lpi025_lmu005_c4
              
PNG_FILES = $(addsuffix .png,$(PNG_FILES_0)) # add .png suffix

EPS_FILES_0 = 
EPS_FILES = $(addsuffix .eps,$(EPS_FILES_0)) # add .eps suffix

PDF_FILES_0 =
PDF_FILES = $(addsuffix .pdf,$(PDF_FILES_0)) # add .pdf suffix

C_FILES_0 = plot_Denethor_HVscan
C_FILES = $(addsuffix .C,$(C_FILES_0)) # add .C suffix


all : CPP_PID_systematics.pdf

CPP_PID_systematics.pdf : $(TEX_FILES) Makefile CPP_PID_systematics.bbl $(PNG_FILES) $(EPS_FILES)  # make the pdf file
	pdflatex CPP_PID_systematics.tex
	pdflatex CPP_PID_systematics.tex

CPP_PID_systematics.bbl : CPP_PID_systematics.bib $(TEX_FILES) $(PNG_FILES) $(EPS_FILES)
	pdflatex CPP_PID_systematics
	bibtex CPP_PID_systematics

tar : $(TEX_FILES) $(PNG_FILES) $(EPS_FILES) # tar files; will remove old tar files
	rm -f CPP_PID_systematics.tar
	rm -f CPP_PID_systematics.tar.gz
	rm -rf CPP_PID_systematics
	mkdir CPP_PID_systematics
#	cp CPP_PID_systematics.ps CPP_PID_systematics
	cp CPP_PID_systematics.bib CPP_PID_systematics
	cp $(TEX_FILES) CPP_PID_systematics
#	cp $(EPS_FILES) CPP_PID_systematics
	cp $(PNG_FILES) CPP_PID_systematics
#	cp $(PDF_FILES) CPP_PID_systematics
#	cp $(C_FILES) CPP_PID_systematics
	cp CPP_PID_systematics.pdf CPP_PID_systematics
	cp Makefile CPP_PID_systematics
	tar cvf CPP_PID_systematics.tar CPP_PID_systematics
	gzip CPP_PID_systematics.tar
#	rm -rf CPP_PID_systematics

%.pdf : %.tex
	pdflatex $*
	pdflatex $*

%.ps : %.ps.gz
	gunzip -l $*.ps.gz
	rm -f $*.ps
	gunzip -c $*.ps.gz > $*.ps

%.eps : %.eps.gz
	gunzip -l $*.eps.gz
	rm -f $*.eps
	gunzip -c $*.eps.gz > $*.eps

#

clean:
	rm -f CPP_PID_systematics.dvi CPP_PID_systematics.ps


