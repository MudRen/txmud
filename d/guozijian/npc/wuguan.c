// wuguan.c

inherit NPC;

int get_box();

void create()
{
	set_name("武官", ({ "wu guan" }) );
	set("long", @LONG
此人的穿着同一般的武官没什么不同，但此人双目有神，印堂
发亮，看来工夫相当了得。
LONG
	);
	set("gender", "男性" );
	set("age", 35);
	set("str", 30);
        set("cor", 24);
        set("per", 27);
        set("int", 25);
        set("attitude", "peaceful");
        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);

        set("max_force", 200);
        set("force",2000);
        set("force_factor",30);

	set("combat_exp", 100000);
        set_skill("unarmed", 90);
        set_skill("dodge", 150);
        set_skill("force", 200);
        set_skill("literate", 70);

        setup();
	carry_object(__DIR__"obj/ruanwei")->wear();
	carry_object(__DIR__"obj/guixin_sword")->wield();
	set("chat_msg_combat", ({
		"武官叫道：你找死啊！\n",
	}) );
	set("inquiry", ([
		"钥匙": "什么钥匙，我不知道。\n",
		"铁盒": (: get_box :),
	]) );
	setup();
}

int get_box()
{
	object me, *inv;
	int i;
	me=this_player();
	inv = all_inventory(me);
        if( sizeof(inv) ) {
  	  for(i=0; i<sizeof(inv); i++){
		if(inv[i]->query("id")=="tiehe" && !userp(inv[i])){
		   write("武官说到：这正是我要找的东西，嘿！！\n");
		   destruct(inv[i]);
	           write("武官抢走了"+me->name(1)+"的铁盒。\n");
		   return 1;
		 }
	  }
	}
        write( "武官说道：什么铁盒，我不知道。\n");
	return 1;
}