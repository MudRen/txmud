// wuguan.c

inherit NPC;

int get_box();

void create()
{
	set_name("���", ({ "wu guan" }) );
	set("long", @LONG
���˵Ĵ���ͬһ������ûʲô��ͬ��������˫Ŀ����ӡ��
���������������൱�˵á�
LONG
	);
	set("gender", "����" );
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
		"��ٽе�������������\n",
	}) );
	set("inquiry", ([
		"Կ��": "ʲôԿ�ף��Ҳ�֪����\n",
		"����": (: get_box :),
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
		   write("���˵������������Ҫ�ҵĶ������٣���\n");
		   destruct(inv[i]);
	           write("���������"+me->name(1)+"�����С�\n");
		   return 1;
		 }
	  }
	}
        write( "���˵����ʲô���У��Ҳ�֪����\n");
	return 1;
}