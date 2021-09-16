// yashang.c
// by dicky

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
	set ("short", "��ɽ֮��");
	set ("long", @LONG
������������ɽ���������������������Ǻ�ȥ����ɽ������Ұ��
����Զ�����ܣ��Ѻ��ɫ�������������Զ������������ƽ����
ɽ���ϳ���������ݣ�Ʈ�ŵ����������㾪��Ŀ������ߺ�����һ��ɽ
ׯ��Ī���Ǿ��Ǵ�˵�еġ���
LONG);

        set("outdoors", "taxue");
	set("exits", ([ /* sizeof() == 3 */
		"north": __DIR__"kongdi",
	]));

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shanya" && arg!="shan") )
		return notify_fail("��Ҫ����������\n");

	if( me->is_busy())
		return notify_fail("�����ں�æ����ʲôѽ��\n");

	if(me->query("class")!="taxue" && me->query("combat_exp")< 2000000)	
		return notify_fail("������ʵս���黹�������޷�����ȥ��\n");

	if(me->query("class")=="taxue" && me->query("combat_exp")< 1000000)	
		return notify_fail("������ʵս���黹�������޷�����ȥ��\n");

	if(me->query("class")!="taxue" && me->query_skill("dodge") < 200)	
		return notify_fail("�������Ṧ���û��������޷�����ȥ��\n");

	if(me->query("class")=="taxue" && me->query_skill("dodge") < 160)	
		return notify_fail("�������Ṧ���û��������޷�����ȥ��\n");

	message_vision(HIC"$N���˽�������Ʒ�������ų���ƮƮ����ɽ�������ȥ��\n"NOR,me);

	me->start_busy(2);

	me->move(__DIR__"yazhong");
	message_vision(HIC"$N����ƮƮ����ɽ���Ϸ��˹�����˫�������ŵأ������Ե�����ô��������\n"NOR,me);
	return 1;
}