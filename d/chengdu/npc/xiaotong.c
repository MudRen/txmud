// xiaotong.c

inherit NPC;
void create()
{
        set_name("Сͯ", ({ "xiao tong"}) );
        set("gender", "����" );
        set("age", 9);
        set("long","һ��ü��Ŀ���С����\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

