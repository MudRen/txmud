// shulin3.c
// by dicky

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
���ܹ������죬�����ܲ���Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ���
��ҹ����������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������Х��
�������ȷ�Ʈ�����ʡ�
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "north" : __DIR__"shulin6",
             "west"  : __DIR__"shulin2",
             "southwest" : __DIR__"shulin",
	]));

	setup();
	replace_program(ROOM);
}
