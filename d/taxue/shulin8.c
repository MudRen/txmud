// shulin5.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "�����");
  set ("long", @LONG
������ï�ܵ�ɭ�֡����ܶ���������ĳ��ݣ�һ����ɭ�ֲ���
���ա�Զ����ʱ����Ұ�޵ĺ��У��ص���ɽ���и���һ�ֲֿ��ĸ�
������ʵ�ڲ��������������
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "south" : __DIR__"shulin5",
             "west"  : __DIR__"shulin7",
             "east"  : __DIR__"shulin9",
	]));

	setup();
	replace_program(ROOM);
}
