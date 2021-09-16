// shiao.c
inherit NPC;
void create()
{
        set_name("马长老", ({ "ma zhanglao" }));
        set("title","八袋长老");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "一个红光满面的老乞丐。正坐在这里喝酒。\n"
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
                "here" : "这里是华阴村么。\n",
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
           
           if ( objname != "『丐帮手信』")
           {
           	command("smile");
		say ( "谢谢您! 让您破费了。\n" );
		call_out("do_dest",1);
		return 1;
           }
           command("smile");
	   say (  "好! 这是我的回信，就烦请你带回去给痴丐长老吧。\n" );
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
