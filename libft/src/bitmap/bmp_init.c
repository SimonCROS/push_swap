#include "libft.h"

void	bmp_free(t_bitmap *image)
{
	if (image)
		free(image->body);
	free(image);
}

t_bitmap	*bmp_init(int width, int height)
{
	t_bitmap	*bitmap;
	int			pixelbytesize;

	bitmap = ft_calloc(1, sizeof(t_bitmap));
	if (!bitmap)
		return (NULL);
	pixelbytesize = width * height * 32;
	bitmap->body = ft_calloc(1, pixelbytesize);
	if (!bitmap->body)
	{
		free(bitmap);
		return (NULL);
	}
	ft_strcpy(bitmap->header.file.signature, "BM");
	bitmap->header.file.filesize = pixelbytesize + sizeof(t_bmpheader);
	bitmap->header.file.data_offset = sizeof(t_bmpheader);
	bitmap->header.infos.dibheadersize = sizeof(t_bmpinfoheader);
	bitmap->header.infos.width = width;
	bitmap->header.infos.height = height;
	bitmap->header.infos.planes = 1;
	bitmap->header.infos.bitsperpixel = 32;
	bitmap->header.infos.imagesize = pixelbytesize;
	return (bitmap);
}
