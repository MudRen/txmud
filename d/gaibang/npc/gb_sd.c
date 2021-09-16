// gd_sd ؤ���ʦ������ϵͳ

#include <ansi.h>

// npc list for gb 1-3 dai promotion
mixed names = ({
       ({
       "����","�ڹ��ķ�","��ʵ��","ͭ��","ľ��","��Ь","ܣ��",
       "�־�","������","������ҩ","Կ��","�Ҳ���","����",
       }),
       ({
       "����","����Ħ�������š�","�䵶","����","ҩ��",HIW "��֮��" NOR,
       YEL "��ͨҩ��" NOR,HIR "Ұ��" NOR,"����","����","��բԿ��",
       }),
       ({
        "��ɽѩ��","�����ܾ�",HIB "��Ϣ�ּ�" NOR,"ҽҩ֪ʶ","ɽ����","������",YEL "С�ƻ�" NOR,
	HIY "ͭҩ¯" NOR,"������ɱ��",HIC "С����" NOR,
       }),
        ({
	"��ת��֥��", HIW "������" NOR,HIW "С�׻�" NOR,HIR "��ɱ��" NOR,"��ϼ����",
	HIR "���" NOR,RED "�ܺ�" NOR,"��ѩ����","����Կ��",HIY "����������" NOR,
          }),
       ({
        HIR "ɱ��֮��" NOR,"�����ڹ�",HIW "�׻�������" NOR,HIR "��������" NOR,
	}),
});

void killing_object(object who);

string ask_me()
{
        object applicant, me;
	int begging_level,position,htlvl;
	string target;

	applicant = this_player();
	me = this_object();

	if ( applicant->query("class") != "gaibang")
		return RANK_D->query_respect(applicant) +"���Ǳ�����ӣ����д��ʣ� \n"; 
 
	position = (int)applicant->query("gb_bags");

	if ( applicant->query_temp("promotion_target") )
               return RANK_D->query_respect(applicant) +"��ȥ���������񣬺�����������\n";

	begging_level = (int)applicant->query_skill("begging",1);

	if ( begging_level < 80 ) 
		return RANK_D->query_respect(applicant) +"�ڰ���������ǳ������������\n";

	if ( ( begging_level < 120 ) && ( position == 2 ) )
		return RANK_D->query_respect(applicant) +"Ҫ�����ͣ�\n";

	if ( ( begging_level < 160 ) && ( position == 3 ) )
		return RANK_D->query_respect(applicant) +"Ҫ���Ŭ�������ڰ��г���ͷ�ء�\n";

	if (( begging_level < 200 )&&(position==4))
		return RANK_D->query_respect(applicant) +"���ǲ���������\n";
	
	htlvl=(int)applicant->query_skill("gaibang-force",1);

	if (( htlvl < 250 ) && (position == 5 ))
		return RANK_D->query_respect(applicant) +"�����书�����Ƿ���ں����ˣ�\n";

        if ( position > 5)
		return RANK_D->query_respect(applicant)+"�Ѿ���ѹȺ���ˣ��Һ����ȥ�ɡ�\n";

        if(applicant->set_temp("promotion_target"))
		return "������ȥ��\n";

	target = names[position-1][random(sizeof(names[position-1]))];
	applicant->set_temp("promotion_target", target);
	applicant->set_temp("assigned_by", me->query("name"));
  
		return "�ðɣ�����Ҫ�����������Ū��ɼ�������\n" + "��ȥ��" + target +"����������\n";
}

int promotion_checking(object who, object ob)
{
        int bag,exp;

	if ( who->query("class") != "gaibang" ) 
		return 0;

	if ( ob->query("name") != (string)who->query_temp("promotion_target")) {
		command("say �ⶫ����Ҫ��û�á�");
		return 0;
	}

	if  ( ob->is_character()) {
		command("say �ⶫ����Ҫ��û�á�");
		return 0;
	}

	if (userp(ob)) {
               command("say " + RANK_D->query_rude(who) + "����Ȼ����ƭ���������������ѣ�");
               call_out("killing_object",1,who);
               return 0;
	}

	bag=(int)who->query("gb_bags",1);        
        exp=(bag*1000);
	who->add("gb_bags",1);

	who->add("max_force",2*bag);

	who->set_skill("begging",(int)who->query_skill("begging",1) + 1);
	who->set_skill("stealing",(int)who->query_skill("stealing",1) + 1);
	who->add("combat_exp",exp);

        command("applaud " + who->query("id"));
	command("say �ɵúã��ӽ��쿪ʼ�������ؤ��" + 
		chinese_number(who->query("gb_bags")) +"�����ӣ��úøɣ�\n");

        who->set("title",sprintf("ؤ��%s������",chinese_number(who->query("gb_bags"))) );
	who->delete_temp("assigned_by");
	who->delete_temp("promotion_target");
	return 1;
}      


void killing_object(object who)
{
       object me = this_object();
       me->kill_ob(who);
       who->unconcious();
}


void gb_apprentice(object ob)
{
	if ( (int)ob->query("gb_bags") >= 2 && ob->query("class") != "gaibang" ) 
	{
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                return;
        }

        if(ob->query("int") > 24)
        {
                command("say �����书��Ҫ���õ����壬�����������ɡ�\n" +
                RANK_D->query_respect(ob) + "��ô��������...��������ɵ��İɣ�");
                return;
        }

        if(ob->query("str") < 24)
        {
                command("say �����书��Ҫ���õ����壬�����������ɡ�\n" +
                RANK_D->query_respect(ob) + "������ô������...��������ɵ��İɣ�");
                return;
        }

        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "gaibang")
                ob->set("gb_bags", 1);

        if (ob->query("class") == "gaibang" && !ob->query("gb_bags"))
                ob->set("gb_bags", 1);

        ob->set("class", "gaibang");
        ob->set("title",sprintf("ؤ��%s������",
                chinese_number(ob->query("gb_bags"))) );
}
