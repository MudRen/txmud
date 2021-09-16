// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *tuned_ch;

	tuned_ch = me->query("channels");

	if( !arg ) {
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("�����ڲ�û�������κ�Ƶ����\n");
		else
			write("������������Ƶ����" + implode(tuned_ch, ", ") + "��\n");
		return 1;
	}

	if( (arg == "paimai") || (arg == "psell") ) // ���⴦��ֻ����ʱ�رյ�Ƶ��
	{
		if(me->query_temp("block_msg/"+arg))
			me->set_temp("block_msg/"+arg,0);
		else
			me->set_temp("block_msg/"+arg,1);
		write("ok.\n");
		return 1;
	}

	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
		write("�ر� " + arg + " Ƶ����\n");
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		return 1;
	} else {
		write("Ҫ��ĳ��Ƶ��ֻҪ�ø�Ƶ��˵�����ɡ�\n");
		return 1;
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tune [<Ƶ������>]

���ָ������ѡ���Ƿ�Ҫ����ĳһƵ����ѶϢ����
��û��ָ��Ƶ�����ƣ��ͻ��г���Ŀǰ�����е�Ƶ
�������ָ����Ƶ����ԭ�������еľͻ�ص�����
֮�򿪡�

������һ��û�������е�Ƶ�����������Զ�����
�򿪡�Ҫ��һ��Ƶ��������ֻҪ�ã�

<Ƶ������> <ѶϢ> ....

Ŀǰ���õ�Ƶ����  
    chat            ����ר�á�
    rumor           ҥ��Ƶ����
    menpai(mp)      ����Ƶ������Ƶ��ֻ��ͬ��
                    �ɵ����ܿ�����
    paimai          �������ר��Ƶ��
    psell           ���˽���ר��Ƶ��

HELP
	);
	return 1;
}

