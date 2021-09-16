inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "tie laoban", "tie" ,"laoban" }) );
        set("gender", "����" );
        set("age", 47);

        set("long", "���ϰ�һ�������е㲻����ˡ���\n");

        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("max_force",800);
	set("force",800);
        set("force_factor",10);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("parry", 120);

        set("sell_all_day",1);

        set("inquiry", ([
                "������" : "����ר�����ֳ��̱���", 
]) );

        set("vendor_goods", ([
                WEAPON_DIR"sword" : 10,
                WEAPON_DIR"whip": 10,
                WEAPON_DIR"dart": 10,
                WEAPON_DIR"sixhammer":10,
                WEAPON_DIR"thin_sword":10,
                WEAPON_DIR"dagger":10,
                WEAPON_DIR"stick":10,
                WEAPON_DIR"blade":10,
]) );

        setup();
        add_money("silver", 1);
        carry_object(WEAPON_DIR"sword")->wield();
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
