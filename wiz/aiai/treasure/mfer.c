// mfer.c

inherit NPC;

//#ifndef F_TREASURE
//#define F_TREASURE            "/d/huashan/obj/treasure"
//#endif

void create()
{
        set_name("�ر���", ({ "mfer", "mf" }) );
        set("title", "ר�ŵ�����");
        set("gender", "����" );
        set("age", 20);
        set("long", "
    �������������������챦����õ���ɱ�ɣ�;)\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("max_kee", 200);

        set("combat_exp", 100);

        setup();
        add_money("silver", 5);
}

void unconcious()
{
        //F_TREASURE->tr_make(this_object());
        __DIR__"treasure"->tr_make(this_object());
        ::unconcious();
}

/*
void die()
{
        //F_TREASURE->tr_make(this_object());
        __DIR__"treasure"->tr_make(this_object());
        ::die();
}
*/
