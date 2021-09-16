// shanya-s.c
// by dicky 2002-12-9

#include <ansi.h>
inherit ROOM;
string look_down();

void create()
{
        set("short","ɽ��");
        set("long", @LONG
�˴����Ǿ�·����ͺͺ��ʯ�ڣ�ͻȻ�ڶ��洫���������ƣ�����������
�����±���һ������׵�����(cliff)������������䣬�����Ѷɡ�������
�����С������һ��С�Ŀ��ܵ������¡������±��п�Ħ�����(tree)��
֦Ҷ��ʢ�����ɡһ������ס��Բ֮�ء�
LONG);
	set("outdoors", "taxue");

        set(SAFE_ENV,1);

	set("exits", ([
		"south" : __DIR__"milin2",
	]));

	set("item_desc",([
		"cliff" : (: look_down :),
		"tree" : "����һ�ÿ�Ħ��������������ۼ���֦Ҷ��ʢ��\n", 
		"down" : "�����ããһƬ��ʲô����������\n", 
	]));

        setup();
}

void init()
{
        add_action("do_jump",({ "tiao", "jump" }));
}

int do_jump(string arg)
{
	object me;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("��Ҫ��������\n");
        message_vision("$N�Ѵ���ݽ������ڱ��󣬳�ɽ�ȷ���������ȥ��\n"NOR, me);

        if (! present("da fengzheng", me) || me->query_skill("dodge", 1) < 300)
          { 
            message_vision("$N��һ�����Ȱ�Ѹ�����䣬˲��͵��������ߣ���æ����ȥץ��ȴ���ֲ��˼��硣\n\n"NOR, me);
            message_vision(RED"��---��$Nһ���ҽУ�ֱ�����������ȥ��\n\n"NOR, me);
            me->receive_damage("kee",9999,"trip");
            me->die();
            return 1;
          }

        message_vision(HIY"$N���ڿ��У��������һ�Գ�������������㣬�����س��ȵ�Ʈ��ȥ��\n\n\n"NOR, me);
	message_vision(HIB"$N���ڲ���Ӧ����״̬���о��е�ͷ�Σ�����$N��Ӧ������״̬������\n\n\n"NOR, me);
	me->start_busy(10);
	call_out("success", 10, me);
	return 1;
}

string look_down()
{
	return "����(down)��ɲ⣬�����������ף������Ҫ��ɱ���⵽�Ǹ��õط���\n";
}

int success(object me)
{
	object ob1;
	message_vision(HIB"$N���ڰ���У��������磬�о���һ�ִ�δ�й��Ĵ̼�������\n\n\n"NOR, me);
        me->move(__DIR__"gudi");
	tell_room(environment(me), me->name() + "���˹�����\n", ({ me }));
	ob1 = present("da fengzheng", me);
	destruct(ob1);
	write(HIY"�����ڰ�ȫ��½��һ�ȵ׵�һ��ʯͷ���档\n"NOR);
	return 1;
}