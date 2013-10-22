# - Berikut adalah contoh Makefile untuk autograde
# - Harus ada perintah compile-test untuk kompilasi dan grade untuk eksekusi
# - OUTPUT adalah variabel yang diperlukan, tidak perlu diubah.
# - ADT1, ADT2, dan MAIN adalah variabel yang berisi nama-nama file,
#   silahkan diubah sesuai kebutuhan.

OUTPUT=bin
ADT1=point
ADT2=arrpos
MAIN=mflight

compile-test: $(MAIN).c $(POINT).o $(ARRPOS).o
	gcc -o $(MAIN) $(MAIN).c $(POINT).o $(ARRPOS).o
	
$(POINT).o: $(POINT).c $(POINT).h
	gcc -c $(POINT).c

$(ARRPOS).o: $(ARRPOS).c $(ARRPOS).h
	gcc -c $(ARRPOS).c

grade: $(MAIN)
	./$(MAIN)
