// banker.c

inherit NPC;

void create()
{
        set_name("����", ({ "gong lei" }) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 56);

        set("str", 52);

        set("long","����һλ���Ƶ����ˡ�\n");

        set("combat_exp", 80);
        set("attitude", "friendly");
        setup();
        
        carry_object(ARMOR_DIR"cloth")->wear();
}
