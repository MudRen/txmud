//yahuan.c
inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "ya huan","ya","huan"}) );
        set("gender", "Ů��" );
        set("age", 14+random(3));
        set("long", "����һ��СѾ������ò�������ס�\n");
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