// wuboss.c

inherit NPC;

void create()
{
        set_name("����ͷ", ({ "wu boss"}) );
        set("title","�ײ����ϰ�");
        set("gender", "����" );
        set("age", 68);
        set("long","����ͷһ���������������ӣ�
����˭��Ƿ��Ǯһ����\n");
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

