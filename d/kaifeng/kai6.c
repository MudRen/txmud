// Room: /wiz/louth/k/kai6.c

inherit ROOM;

void create()
{
	set("short", "�䳡��Ժ");
	set("long", @LONG
����������䳡����Ժ������䳡�ĵ�����һ���ǲ��õ���
��ģ�ֻ�й������Ʒ�ر�õĵ��ӣ���ʦ�������������ﴫ��
һЩ������书�������ɨ�÷ǳ��ɾ���Ժ��ս�����һ�Ŵִ�
�Ļ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai5",
]));
        set("objects",([
        __DIR__"npc/jiaotou" : 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
