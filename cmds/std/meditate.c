// meditate.c
// by Find.

#include <ansi.h>
inherit F_CLEAN_UP;

string *m_msg = ({
"ε�����������һ���޼ʵĲ�ԭ����ԭ����Ⱥ��վ��һ����ͯ��
��������һֻ��ɫ�ĵ��ӣ����ڴ��������������",
"���һƬ�谵����������Ʒ�����һ���������Ʋ��д��󣬲�ʱ
�ķ������춯�ص����У��·�Ԥʾ������Ļ���",
"����������������ʬ��Ѫ���ɺӣ�һλ������ʿվ�������ǰ��
����һ�ѵ�Ѫ�ı�����������㯵�����ǰ��",
"�����죬�ƻ��أ������棬��Զ��һλ�����������Ů����һ
֦õ�建������������",
"��Ƶ�Ϧ��ӳ�����ޱ��޼ʵ�ɳĮ��Զ��һֻ�ն��ڻ������ƶ���
��ʱ��������������������",
"һλ��Ŀ������������Ѫ���������ӣ�����һ����Ѫ�Ĵ󵶣���
��ӯ������ˮ���ڳ�����տ�Ц",
"һƬ�޴��լԺ�Ѿ�����𺣣�Ũ�̳�����𣬻��ӳ���˰��
�죬��Զ����ɽ������һλ�������̵�������������������",
"�峿�ı�������һ���ľ���С��԰�������Ļ����Ϲ��ŵ��¶�飬
ż��һ���������鿪��ӳ���߲ʹ���",
});

int main(object me, string arg)
{
	int sen_cost, mana_gain;

	if( me->is_fighting() ) return notify_fail("ս�����޷�����ڤ˼��\n");

	if( !arg || !sscanf(arg, "%d", sen_cost) )
		return notify_fail("��Ҫ�����پ���ڤ˼��\n");

	if( sen_cost < 10 )
		return notify_fail("������Ҫ�� 10 �㡸�񡹲���ڤ˼��\n");

	if( (int)me->query("sen") < sen_cost )
		return notify_fail("�����ھ���̫���ˣ�����ڤ˼������ʧ����Զ�Ѳ�������\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
		return notify_fail("����������״��̫���ˣ��޷����о���\n");

	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
		return notify_fail("����������״��̫�����ˣ��޷�����ڤ˼��״̬��\n");

	if( !me->query_skill("spells",1) )
		return notify_fail("����ϥ����������ڤ˼��һ�����\n�������û��ѧϰ������������������ֻ����������һƬ�հס�\n");

	mana_gain = sen_cost * ((int)me->query_skill("spells")
		+ (int)me->query("con") ) / 300;

	if(mana_gain < 1)
		mana_gain = 1;

	me->receive_damage("sen", sen_cost);
	message_vision("$N��ϥ���£������ı���˫�ۿ�ʼڤ˼������������\n",me);

	me->start_busy(5);
	call_out("continue_mingsi",2,me,mana_gain);

	return 1;
}

private void continue_mingsi(object me,int gain)
{
	if(!objectp(me))
		return;

	write(sprintf("\n��·𿴵�%s��\n\n",m_msg[random(sizeof(m_msg))]));
	call_out("quit_mingsi",2,me,gain);
}

private void quit_mingsi(object me,int gain)
{
	if(!objectp(me))
		return;

	seteuid(getuid());

	write("���ڤ˼�������˹��������������ۣ���Χ�ľ��･���������ˡ�\n");
	tell_room(environment(me),me->name()+"��ڤ˼�������˹�����������һ���������������ۡ�\n",({me}));

	me->add("mana", gain );

	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
		if( (int)me->query("max_mana") >= (int)me->query_skill("spells", 1) * 10) {
			write("����ķ������ӵ�˲�����Ȼ��������һƬ���ң��ƺ�ħ���������Ѿ�����ƿ����\n");
		} else {
			write(HIC"���������һ����������ǿ����ġ�����������ˡ�\n"NOR);
			me->add("max_mana", 1);
		}
		me->set("mana", me->query("max_mana"));
	}
	me->stop_busy();
}

int help(object me)
{
        write(@HELP
ָ���ʽ : meditate [<�ķѡ��񡹵�����Ԥ��ֵ 30>]
 
����ڤ˼��������ľ�������Ч�ؼ������۳��ܹ�����ʩչ����������
�����������Լ��ķ�����

��ο� help stat 
HELP
        );
        return 1;
}
