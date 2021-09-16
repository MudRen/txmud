inherit NPC;
inherit F_MASTER;

string
*to_sleep = ({"southwest","southwest"}), /* ȥ˯����·�� */
*go_back = ({"northeast","northeast"}); /* ��ȥ��·�� */

void create()
{
        set_name("��ͮ", ({ "master tong", "master", "tong" }) );
        set("class","jinghai");
        create_family("������", 2, "����");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "�뿪" : (: call_other, __FILE__, "want_to_leave" :),
        "��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
]));

        set("gender", "Ů��" );
        set("age", 25);
        set("attitude", "peaceful");

        set("long", "����һλ���ĵ�����Ů�ӣ������Ǿ�
���ɵĴ�ʼ�˷򸾵�СŮ����\n");

        set("combat_exp", 1800000);
        set("str", 40);
        set("per", 21);
        set("max_kee",2000);
        set("kee",2000);
        set("max_gin",2000);
        set("gin",2000);
        set("max_sen",2000);
        set("sen",2000);
        set("force", 2500);
        set("max_force", 2500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 50);
       set("chat_chance",3);
        set("chat_msg",({
        "��ͮ�ߵ�����ͨ�������ô���˿��ţ��಻����˼��\n"
}));

        set_skill("jinghai-force",200);
        set_skill("longjiao-blade",200);
        set_skill("literate",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("jiachuan-shu",220);
        set_skill("houyi-bow",220);
        set_skill("bow",220);
        set_skill("liangqing-xiangyi",220);
        set_skill("moonlight-sword",200);
        set_skill("sword",200);
        set_skill("bibo-sword",200);
        set_skill("perception",200);
        set_skill("xian-steps",220);

        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","liangqing-xiangyi");
        map_skill("sword","liangqing-xiangyi");

        setup();
	call_out("do_setup",1);
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();

}

void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "����")
        {
                command("say ������е��ӣ�ȥ�����ҵ�ʦ���ǰɡ�");
                return;
        }

        command("shake");
        return;

        if(!ob->query_temp("pass_shengji_quest"))
                return;
        else
        {
                command("smile");
                command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

void do_setup()
{
	int n;

	if(!clonep()
	|| !environment()
	|| (base_name(environment()) != query("startroom")))
		return;

	n = 1440 - query_time();
	call_out("goto_sleep",n);
}

void goto_sleep()
{
	if(!environment())
		return;
	remove_call_out("goto_sleep");
	call_out("goto_sleep",1440);
	tell_room(environment(),sprintf("%s���˸�����˵�����������ˣ����е����ˣ�Ҫ��ȥ��Ϣһ�¡�\n��",
		name()));
	call_out("do_go",1,0,1);
}

void do_go(int step,int flag)
{
	remove_call_out("do_go");
	command(sprintf("go %s",(flag?to_sleep:go_back)[step]));
	if(++step < sizeof(flag?to_sleep:go_back))
	{
		call_out("do_go",1,step,flag);
		return;
	}
	else if(flag)
		command("sleep");
}

void have_wake_up()
{
	call_out("do_go",1,0,0);
}
