// Room: /d/huanggong/dongg6.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������С�ĸ�����¡�֮�ƵĻʺ���޹������沼�õĸ�
���ûʡ�����ĵ�̺���ڵ��ϣ���ɴΧ��֮��ɢ�������˵�����
�����˼��ɾ�һ�㡣��͵��˻ʺ�һ�ۣ������������ǵ���ò
����̬�򷽵ľ�ֹ���㵹,������ʱ����һ˿Ī���ĳ嶯....

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"dongg1",
  "south" : __DIR__"dongg4",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}