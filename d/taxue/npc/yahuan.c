//yahuan.c
inherit NPC;

void create()
{
        set_name("丫环", ({ "ya huan","ya","huan"}) );
        set("gender", "女性" );
        set("age", 14+random(3));
        set("long", "这是一个小丫环，容貌清秀脱俗。\n");
        set("shen_type", 1);
        set("combat_exp", 30000);
        set("str", 18);
        set("dex", 18);
        set("con", 18);
        set("int", 19);

        set_skill("unarmed",30);
        set_skill("dodge",30);
        set_skill("parry",30);
        set_skill("force",30);
        set_skill("sword",30);	  

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
} 