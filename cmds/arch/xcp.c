// �����:����(bate)
// ʱ��: 1998/08/25
// xcp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src,dst;
	string src_dir,dst_dir,dir;
	string s_flag,t_flag;
	mixed *file;
	int i, j;
	int ok,nook; 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

	dst = resolve_path(me->query("cwd"), dst);
	for(i=0;i<strlen(dst);i++) {
		if(dst[i] == '*') return notify_fail("���ڲ�֧��Ŀ�굵����*��.\n");
	}
	if (file_size(dst) != -2) 	return notify_fail("Ŀ��Ŀ¼�����ڡ�\n");
	t_flag = " ";
	if( file_size(dst)==-2) {
		t_flag="/";
		if(dst[strlen(dst)-1] != '/' ) dst += "/";
	}
	file = get_dir(dst, -1);
	src = resolve_path(me->query("cwd"), src);
	s_flag=" ";
	for(i=strlen(src)-1;i>=0;i--) {
		if(src[i] == '/') break;
	}
	dir = src[0..i];
	if( file_size(src)==-2) return notify_fail("��Ҫ����ʲô��?\n");
	file = get_dir(src, -1);
	if( !sizeof(file) )
	{if (file_size(src) == -2) return notify_fail("��Ҫ����ʲô��?\n");
		else
		return notify_fail("û�����Ŀ¼��\n");
	}
	ok = 0;
	nook = 0;
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++) {
			if( file[i][1] == -2) continue;
			if( t_flag == "/") dst_dir = dst + file[i][0];
			src_dir = dir + file[i][0];
			if( cp(src_dir, dst_dir) ) ok++;
			else nook++;
		}

	printf("�㿽���ɹ�%d���ļ�,ʧ��%d���ļ���\n",ok,nook);
	return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : xpp <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)����������
HELP
    );
    return 1;
}