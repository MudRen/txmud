//lady.c ��֥������ٸ���
inherit NPC;
void create()
{
        set_name("�����ٸ�", ({ "young lady", "lady" }) );
        set("gender", "Ů��" );
        set("age", 27);
        set("long", "һλ����ļ�ͥ������\n");

        set("combat_exp", 20000);
        set("attitude", "friendly");
        set("max_kee",300);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("blade", 50);
        set_skill("parry", 70);

        setup();
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
                        command(sprintf("say ��λ%s�����ȱ��̲�ɡ�",RANK_D->query_respect(ob)));
  break;
                case 1:
                        command("say ����λ��ȥ�ˣ���������");
                        break;
        }
}
