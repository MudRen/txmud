// shenmi.c

inherit NPC;

int ask_me(object me);

void create()
{
        set_name("白衣男子", ({ "shenmi man","man"}) );
        set("gender", "男性" );
        set("age", 23);
        set("attitude", "peaceful");
        set("per",30);
        set("combat_exp",100);
        set("inquiry", ([
                "夜蝶" : ("夜蝶是我的妻子，她住在绯雨阁里。\n"),
                "花球" : (: ask_me :),
        ]) );

        set("long","这是一位神秘的白衣男子，面上挂着
无尽的相思，好象在思念着什么人。\n");

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object me)
{
        object ob;

        if(!me->query("mark/louth_huaqiu"))
        {
		if(objectp(present("flower ball",me)))
		{
			command("say 不是已经给你了吗？");
			return 1;
		}

                command ("say 麻烦你一件事，帮我把这个花球带给我妻子，
她一定会很高兴的。多谢了。\n");
		ob=new(__DIR__"obj/huaqiu");    
		ob->move(me);
		return 1;
        }

	command ("say 上次的事多谢你了。\n");
	return 1;
}
