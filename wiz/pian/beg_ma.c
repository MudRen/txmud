// shiao.c
inherit NPC;
void create()
{
        set_name("����", ({ "ma zhanglao" }));
        set("title","�˴�����");
        set("gender", "����");
        set("age", 54);
        set("long",
                "һ��������������ؤ������������Ⱦơ�\n"
                "  \n");
     //  set("attitude", "peaceful");
        set("str", 20);
        set("int", 30);
       /*   set("combat_exp", 4000000);
                set("chat_chance_combat", 80);
      set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );        
       */ 
        set("force", 600);
        set("max_force", 600);
        set("force_factor", 5);
        
        set("atman", 600);
        set("max_atman", 600);
        
        set("mana", 2000);
        set("max_mana", 1200);
        set("mana_factor", 5);
        
        set("inquiry", ([
                "here" : "�����ǻ�����ô��\n",
        ]) );
        
        set_skill("literate", 360);
        set_skill("force", 325);
        set_skill("spells", 200);
        set_skill("unarmed", 330);
        set_skill("sword", 340);
        set_skill("parry", 335);
        set_skill("dodge", 340);

        setup();
        
}
int accept_object(object who,object ob)
{
           object me,obb;
           string objname;
           
           objname = (string)ob->name();
           me = this_player();
           
           if ( objname != "��ؤ�����š�")
           {
           	command("smile");
		say ( "лл��! �����Ʒ��ˡ�\n" );
		call_out("do_dest",1);
		return 1;
           }
           command("smile");
	   say (  "��! �����ҵĻ��ţ��ͷ��������ȥ����ؤ���ϰɡ�\n" );
	   obb = new("/d/obj/gaibang/huixin_ma");
	   
	   if( !obb->move(me) ) destruct(obb);
	   call_out("do_dest",1);
           return 1;
}

protected void do_dest()
{
	object *obs;

	obs = all_inventory(this_object()) - ({0});

	if(!arrayp(obs) || !sizeof(obs))
		return;

	obs = filter_array(obs,(: !$1->query("equipped") :));

	if(sizeof(obs))
		foreach(object ob in obs)
			destruct(ob);
}
