inherit NPC;

void create()
{
        set_name("赵老爷子", ({ "zhao lao" , "zhao"}) );
        set("gender", "男性" );
        set("age", 65);
        set("long", "好象赵老爷子当年......\n");

        set("combat_exp", 20000);
        set("attitude", "heroism");

	set("max_kee",800);
	set("max_gin",800);
	set("max_sen",800);
        set_skill("unarmed", 30);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        setup();
        add_money("silver", 1);
        carry_object(ARMOR_DIR"cloth")->wear();        
}
