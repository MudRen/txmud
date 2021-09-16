//w_boss.c
inherit F_DEALER;
void create()
{
        set_name("�Ծߵ��ϰ�", ({ "weapon boss", "boss" }) );
        set("gender", "����" );
        set("age", 45);
        set("per",10);
        set("long", "һλ��ĸߴ�Ĳ��ˣ���ǰ����֥�������Ի���\n");

        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("max_kee",1300);
        set("max_force",2000);
        set("force_factor",20);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("blade", 150);
        set_skill("parry", 170);

        set("sell_all_day",1);

        set("inquiry", ([
                "�Ծߵ�" : "����ר�������Ծ�", 
]) );

        set("vendor_goods", ([
                __DIR__"obj/hunt-fork":-1,
                __DIR__"obj/zang-blade":-1,
                "/d/changan/npc/obj/neck":50,
                "/d/changan/npc/obj/hu_boot":50,
]) );
 
        setup();
        carry_object(__DIR__"obj/zang-blade")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;
        switch( random(4) )
        {
                case 0:
                        command(sprintf("say ��λ%s��һ�����ֵı����ɡ�", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}
