//d_boss.c ��֥�嵱���ϰ塣
inherit NPC;
void create()
{
        set_name("����", ({ "gong bu","boss" }) );
        set("gender", "����" );
        set("title","�����ϰ�");
        set("age", 29);
        set("long","һλ����ȥ�ǳ����������ꡣ\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
