// Room: /d/death/road2.c
 
inherit ROOM;
 
void create()
{
        set("short", "���޵�");
        set("long", @LONG
��������λ�һ����������Ĵ���ϣ�����Ĺ���ʮ��������
��������Ȼ���Ժ�����ؿ��������������ı�����һ����
������������˺����飬�����������һλ��������������
��������ʮ��˫�˺ϱ��Ļ��ɫԲ����Բ������վ�����Ų�֪��
�˻��ǹ�ĺ�Ӱ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/death/road1",
]));

	set("objects",([
	__DIR__"npc/yanluo" : 1,
]));
	set("no_magic", 1);
        setup();
}