LuaQ                  
      
@  E   	@ @  À  E   	@    d   	@   d@  	@    d  	@   dÀ  	@   	   	   DemoExit    DemoExitMT    __index    screens 	   demoexit    Create    Destroy    Update 
   MouseMove           1     
x   J      À  A  @  À@À   @A @   À @ BÀBÁ @     @ BÀB @  Å ÎÀ @ @ @D E @ @ ÀD@ BÀBA @     @ BÀB @ @    À @     Å ÎÀ AG EÁ FÇKÁÇÅ  \A EÁ FÇKAÈÀ  \A EÁ FÇKÈÅÁ ÆÉ\AEÁ FÇKAÈÀ \A EÁ FÇKÈÅÁ ÆAÉ\AE FÉZ  ÀE KÁÉÁ
 \Z  @ IJ EÂ
  A
 A
 KA ^    -      setmetatable    DemoExitMT    PRELOAD_GFX     game    DemandImageDirectory    Images/general    ost    Sprite    display 	   viewport 
   add_child    story    general    SCALER þ-   þ   
   set_scale    depth þÿÿÿÿ   sel 	   selected þ      submitFailed    submitWait þ    þÿÿÿþ°ÿÿÿ
   fontsmall    get_height    canvas 	   set_font    WHITE    move_to    write    lang 
   demoExit2 
   demoExit3    audio 
   FindSound    Sounds/typewriter.wav    typewriter    play 	   S_VOLUME    pause                     3   L     8   E   @À À E  KÀÀ Á  \@E@ FÁ KÀÁ Å  \@C  G  E@ FÁ KÀÁ Å@ \@C  G@ E@ FÁ KÀÁ Å \@C  G E@ FÁ KÀÁ ÅÀ \@C  GÀ E  Z    E  K@Ã \@ C  G  C  G C  GÀ C  G  C  G@ C  G C  GÀ         PRELOAD_GFX     game    UnDemandImageDirectory    Images/general    display 	   viewport    remove_child    ost    story    sel    general    typewriter    stop 	   selected 	   wasdown1 	   wasdown2    wasmovedup    wasmodeddown 	   wasdownM                     N   Ñ          @@  Á@Å  ÎÀ ÁA E NAA BÁBA A BC E MÂÃNMBDL DMA A BAD E NBA A BAD E NBA A BEA A BÁEA  BÁBA  BAF A Å   ÂFE NB ÅA À ÅÁ ÆÈB GBHHÜ Â I@    Â BI@  À  	   À	 ÂI  J 	 BJB B JEÂ FÂÊK\   E  Â EB FËZ   EB KÂËÁ   AC ÕB\Z  À BÂBB  BÂL A C B BMB À	    	 ÂMB B NEÂ FÂÊK\  CB K  @ @B ÂKC @  B ÂK @ Z   BÂBB  BÂL A C B BMB  BC Å ÎÂB  BO BÅA  Ü B EÂ  E  Ê@Ð E @@E Â \B E MÂÃG Ç E  Ê@P E @Ã@E Â \B E LÂÃG  EB B \ ZB   EB  \ B ÅÂ  Â       CR J  RÃ À   J@Ð  CSE FÓ @ C@  ÄS@@À  Á C C TÅ  ÆÃÔC    C@  U@À@@ Á C C CUC  ÃUC ÀÿÇ   J@@ÐÀ ÀC  A C C TE  FÃÔC À  D  A C C CUC  ÃUC G C  J@@PÀ ÀC  A C C TE  FÃÔC À  D  A C C CUC  ÃUC B   Z      fontbig 
   get_width    lang 	   demoOver    SCALER þÿÿÿ
   fontsmall    get_height þ°ÿÿÿ   sel    canvas    clear    move_to þ   	   selected þ   þ      rel_line_to þûÿÿÿþ   þ    þöÿÿÿ   close_path    fill    story 	   set_font 	   WrapText 	   demoExit þÄ      screen_time þô     math    floor þè  þ2      string    len    sub    typewriter    is_playing  
   play_loop þ,     ceil þd      game    images 
   FindImage    Images/general/    .png    general    set_source_image þ@   þèÿÿÿ   paint    stop þÐ     Images/general/1.png    Images/general/blink.png þòÿÿÿ   write    IsDown 
   ACTION_UP    ACTION_DOWN    wasmovedup 
   PlaySound    Sounds/select.wav    wasmoveddown 	   ACTION_1    ACTION_START 	   ACTION_2    mouse    hidden    is_down    MBUTTON_LEFT 	   wasdownM    xaxis    yaxis 
   demoExit2    Sounds/start.wav    system 	   open_url    url 
   demoExit3    Destroy    display    destroy 	   wasdown1 	   wasdown2                     Ó   é     A   Å   Æ@ÀÀ    ÅÀ  ÎÀ A A EÁ  NA  BÅ  ÆAÂ@B BÂ C @ÀÀ  B WC@Â A B  B À@B BÂ BD @À@ B WD@Â A B  B Àÿ        mouse    hidden    SCALER þÿÿÿ
   fontsmall    get_height þ°ÿÿÿ   xaxis    yaxis 
   get_width    lang 
   demoExit2 	   selected þ   
   PlaySound    Sounds/select.wav 
   demoExit3 þ                               