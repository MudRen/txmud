// smith.c

inherit NPC;

void create()
{
	set_name("Ī��ǫ", ({ "mo ti qian"}) );
	set("title","������ر�");
        set("gender", "����" );
        set("age", 58);
	set("str",60);
        set("long", "�����ǻ�����ĵر�����˵��
�Ǵ�ͬ��֪�������ݡ�\n");

        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}