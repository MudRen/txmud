// Room: /u/w/wangs/b/kai130.c

inherit ROOM;

void create()
{
	set("short", "�೦��");
	set("long", @LONG
�೦������沢����װ��Ҳ����������������ϰ岻����
�Խ�һ��������һ������ֲ�ͬ�ĵĳ��������ǹ�����һ������
ˤ�Ӹ��֡����������ſ�Ƥ����ͺ���Դ���ͦ����վ���ſڣ���
�ǿ�����ơ���������Ľ���������û�е��೦��������������
��������е㲻����˼��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai129",
]));

        set("objects",([
        __DIR__"npc/gcboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
