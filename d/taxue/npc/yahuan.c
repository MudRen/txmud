//yahuan.c
inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "ya huan","ya","huan"}) );
        set("gender", "Ů��" );
        set("age", 14+random(3));
        set("long", "����һ��СѾ������ò�������ס�\n");
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