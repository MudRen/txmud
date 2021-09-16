// cooker.c
// by Find.

#include <ansi.h>
inherit NPC;

string ask_me(object who);

void create()
{
	set_name("��һ��", ({ "liu yishou" }) );
	set("gender", "����" );
	set("age", 45);
	set("long", "����һλ�������ˣ����Ŀ�ü����һ���Ͳ���һ
�����ˣ��Ӵ���Ͽ������һ��ʦү��\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN+"��һ��˵�������Ӿ��ǹ���Ҫ;���ڷ�ɽ�������˽ٵ�����\n" +NOR,
		CYN+"��һ��˵�������ڷ�ɽ�ϵĺڷ�կ��������\n"+NOR,
	}) );
	set("inquiry",([
	"�ڷ�ɽ" : (: ask_me :),
	"�ڷ�կ" : (: ask_me :),
]));
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	if(who->query_temp("hangzhou_shiye"))
		return "����Ҷ��죡�����ҳ���ĭ������ѽ��\n";

	who->set_temp("hangzhou_shiye",1);

	return "�ڷ�կ�Ĵ�կ��������ҵ����е㽻�飬����һ�仰·������
           �ͺ��Լ���һ����ȫ����������ʦү�����Ӻ���࣬Ҫ������
           �� 100 �����ӣ���ʱ�ͺð��ˡ�";
}

int accept_object(object me,object ob)
{
	string pass, *l = ({ "С��","����","����","��Ҫ" }),
		*m = ({ "����","�ݼ�","�μ�","����","����" }),
		*n = ({ "կ��","�ϴ�","��կ��","��կ��","ͷ��" });

	if(!is_money(ob))
		return 0;

	if(!me->query_temp("hangzhou_shiye"))
	{
		command("say ���������׸�Ǯ�����鶼�У�лл����");
                return 1;
	}

	if(ob->value() < 10000)
	{
		command("say �⼸��Ǯ����ʲô�ģ���������һƬТ�ľ������ˡ�Ҳ�����̻�����������\n");
                return 1;
	}

	me->delete_temp("hangzhou_shiye");

	pass = sprintf("%s%s%s",l[random(sizeof(l))],m[random(sizeof(m))],n[random(sizeof(n))]);

	command(sprintf("tell %s �㵽ɽկ�ſں�һ�� %s �Ϳ����ˡ��мǣ�\n",
		me->query("id"),pass));

	me->set_temp("enter_heifeng",pass);
	return 1;
}
