// yedie.c

#include <ansi.h>
inherit NPC;

//string ask_me(object me);

void create()
{
        set_name("ҹ��", ({ "ye die" , "die"}) );
        set("gender", "Ů��" );
        set("age",18 );
        set("nickname",HIC"ѩ֮��  ���и�"NOR);
        set("long", "������ѩ�����Ľᾧ ӵ������ľ���,�·��Ʊ�ѩ
��͸,��������������ҹ��Ĵ���˸�ŵ���ǹ�,��
�ؼ�����Ϊ֮�㵹��\n");
        set("title",HIW"�����֮����--ѩ������"NOR);
        set("combat_exp", 100);
        set("per", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
                "ҹ�����ĵĳ���������Ʈ��Ц�쳾����ȻһЦϷ���졣����\n",
                "ҹ�����ĵĿ��˳�����������\n",
                "ҹ��̾����ħ��ħ ���ǵ� �ƶ������� ������ ����� ��Ե���춨��\n",
        }) );
        set("inquiry", ([
	"��" : "��������Ϊ�������������\n", 
        //"��ָ" : (: ask_me :),
]) );

	setup();
	carry_object(__DIR__"obj/nishang")->wear();
}

int accept_object(object me, object ob)
{
	if(me->query("class") != "rain")
		return 0;

	if(ob->query("id") == "flower ball")
	{
		if(me->query("mark/louth_huaqiu"))
		{
			tell_object(me,"ҹ��˵������л�����ϴξ�����������������ҵġ�\n");
			return 1;
		}

		command("say ̫����,������������Ϲ�����!!");
		command("say ����ô��л���أ���\n");
		command("think");
		call_out("thanks",8,me);
		return 1;
	}

	switch(ob->query("id"))
	{
		case "red flower":
			call_out("greeting",6,me,1);
			break;
		case "yellow flower":
			call_out("greeting",6,me,2);
			break;
		case "blue flower":
			call_out("greeting",6,me,3);
			break;
		case "purple flower":
			call_out("greeting",6,me,4);
			break;
		case "white flower":
			call_out("greeting",6,me,5);
			break;
		default:
			return 0;
	}

	return 1;
}

void greeting(object me,int n)
{
	if(!objectp(me) || (environment(me) != environment()))
		return;

	switch (n)
	{
		case 1:
			tell_object(me,"ҹ��С����˵��������һ�����ܣ���˵������һ�ѱ�����
���˽������±ߣ�һֱû�����ҵ�����\n");
			break;;
		case 2:
			tell_object(me,"ҹ��С����˵���ٸ�����һ�����ܣ���˵Ҫ��˭��������һ��
����ܲ�ġ����Ǹ��˾��ܴӻ�������ѧ���ܶ�֪ʶ��\n");
			break;
		case 3:
			tell_object(me,"ҹ��С����˵���ٸ�����һ�����ܣ���˵��÷��������һλ˭Ҳ
û�������ˣ��Ǹ���һֱ���������ߣ���һ����͵͵�������Ǹ���˵ʲô����ɱ��ʲô��������\n");
			break;
		case 4:
			tell_object(me,"ҹ��С����˵���ٸ�����һ�����ܣ���˵������ǰ��ʱ���и���
�Ӹ�����ܲҪ���������ǿ�������ܲ��һ�η������������ѽ��\n");
			break;
		case 5:
			tell_object(me,"ҹ��С����˵������ٸ�����һ�����ܣ���˵�������м�������
�������޵�������\n");
			break;
	}
}

void thanks(object me)
{
	if(!objectp(me) || (environment(me) != environment()))
		return;

	message_vision("ҹ���������������$N��ͷ��������\n",this_player());
	message_vision("$Nֻ����һ�����˴�ҹ�����Ĵ���������\n",this_player());
	command ("say ���ˣ���Ĺ����Ѿ�����ˡ�\n");
	me->add("max_force",200);
	me->set("mark/louth_huaqiu",1);
}
