// tudu_seng.c

inherit NPC;

string ask_tudu(object who);
mixed ask_huansu(object me);
protected void decide_beipan(string, object);

void create()
{
	set_name("�޿�", ({ "hui kong","seng" }) );
	set("title","���ɮ");

	set("class","shaolin");
	set("gender", "����" );
	set("age", 95);
	set("long", "����һλ�������ƾ��ݵ�һλ��ɮ������
�����ϱ�Ŀ������\n");
	set("attitude", "peaceful");

	set("combat_exp", 200000);
	set("str", 27);
	set("max_kee",3500);
	set("kee",3500);
	set("force", 9000);
	set("max_force", 9000);
	set("force_factor", 200);

	set("inquiry",([
	"���" : (: ask_tudu :),
	"tidu" : (: ask_tudu :),
	"����" : (: ask_huansu :),
	"huansu" : (: ask_huansu :),
]));

	setup();

	carry_object(__DIR__"obj/seng_pao")->wear();
}

void init()
{
	add_action("do_kneel","kneel");
}

string ask_tudu(object who)
{
        if(who->query("marry"))
                return "���ֲ������ѻ���֮�ˡ�\n";

	if(who->query("is_bonze"))
		return "������"+(who->query("class") == "shaolin"?"���µ�":"")+"����ɮ�ˡ�\n";

	if(who->query("gender") != "����")
		return "�����ӷ���λŮʩ���뵽����ȥ��Ȱɡ�\n";

	if(who->query("ever_bonze"))
		return "�����ӷ������²�����������������֮�ˡ�\n";

	who->set_temp("pending/want_tudu", 1);
	return "�����ӷ�ʩ��������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel(string arg)
{
	object who = this_player();
	string title;

	if(!who->query_temp("pending/want_tudu"))
		return 0;

	who->delete_temp("pending/want_tudu");

	if(!sscanf(who->query("title"),"�����µ�%s������",title))
		who->set("title","�����º���");
	who->set("is_bonze",1);
	message_vision("$N˫�ֺ�ʮ�����������ع���������\n\n\
$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n", who, this_object() );
	command("say �ӽ��Ժ�����Ǳ��µ�ɮ���ˣ���������Ժã������޳�������\n");
	who->save();
	return 1;
}

mixed ask_huansu(object me)
{
	if(!me->query("is_bonze"))
		return "�㲢û�г���Ϊɮ����Ҫ������ô�ף�������\n";

	tell_object(me, "
���ѷ��Ż�ʧȥ���еķ����У����ֶ����������ѷ���
֮�˾������������Ƿ�������ѷ��ţ�(y/n)");

	input_to((: decide_beipan :), me);
	return 1;
}

protected void decide_beipan(string str, object me)
{
	if(!sizeof(str) || (str[0] != 'y'))
	{
		tell_object(me, "\n�޿�˵���������������ǡ�\n");
		return;
	}

	me->delete("is_bonze");
	if(me->query_skill("dacheng-fofa"))
		me->delete_skill("dacheng-fofa");
	if(me->query_skill("chant"))
		me->delete_skill("chant");
	me->set("ever_bonze",1);
	if(me->query("title") == "�����º���")
		me->set("title","��ͨ����");
	me->save();
	tell_object(me, "\n�ðɣ���ӽ��Ժ������Ե����������ˡ�\n");
}
