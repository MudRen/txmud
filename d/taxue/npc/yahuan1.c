//yahuan.c
inherit NPC;

void create()
{
        set_name("丫环", ({ "ya huan","ya","huan"}) );
        set("gender", "女性" );
        set("age", 14+random(3));
        set("long", "这是一个小丫环，容貌清秀脱俗。\n");
        set("shen_type", 1);
        set("combat_exp", 50000);
        set("str", 18);
        set("dex", 18);
        set("con", 18);
        set("int", 19);

        set("max_kee",400);
        set("max_gin",400);
        set("max_sen",400);

        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("force",50);
        set_skill("sword",50);	  

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
} 